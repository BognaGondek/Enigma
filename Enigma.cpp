#include "Enigma.h"
#include <iostream>

#define MAX_MOVING_ROTOR_INDEX 2

Enigma::Enigma()
{
    entryWheel = EntryWheel();
    reflector = Reflector();
    rotorsNumber = 0;
    rotors = nullptr;
    message = nullptr;
    messageSize = 0;
    currrentCodeLength = 0;
    code = nullptr;
}

Enigma::Enigma(Repository& repository, int* input)
{
    int inputLength = 2 + 2 * input[0];
    rotorsNumber = input[0];
    entryWheel = repository.entryWheel;
    
#if TEST == true
    printf("PREPARING\n");
    entryWheel.print();
#endif

    rotors = new Rotor[input[0]];
    for (int i = 0, j = 1;
        i < input[0], j < inputLength - 1;
        i++, j += 2)
    {
        rotors[i] = repository.rotors[input[j]];
        rotors[i].setPosition(input[j + 1] - 1);
        if (i == 0)
        {
            rotors[i].setFirstRotor(true);
        }
        rotors[i].setIsRatcherUncovered();
        if (i == 1)
        {
            rotors[i].secondRotor = true;
        }

#if TEST == true
     rotors[i].print();
#endif

    }
    reflector = repository.reflectors[input[inputLength - 1]];

#if TEST == true
  reflector.print();
#endif

    message = nullptr;
    code = nullptr;
    messageSize = 0;
    currrentCodeLength = 0;
}

void Enigma::setMessage(int* message)
{
    messageSize = messageLength(message);
    this->message = new int[messageSize];
    for (int i = 0; i < messageSize; i++)
    {
        this->message[i] = message[i];
    }
    code = new int[messageSize];
}

void Enigma::setCode()
{   
    rotors[0].setPosition(1);
    
#if TEST == true
    for (int i = 0; i < 3; i++)
    {
        rotors[i].print();
    }
#endif
    setOneNumber();
    //rotors[0].print();
    //rotors[1].print();
    for (int i = 1; i < messageSize; i++)
    {
        moveRotors();
#if TEST == true
        for (int i = 0; i < 3; i++)
        {

            rotors[i].print();
        }
#endif
        setOneNumber();

#if TEST == true
        for (int j = 0; j < rotorsNumber; j++)
        {
            this->rotors[j].print();
        }
#endif

    }
    for (int i = 0; i < currrentCodeLength; i++)
    {
        printf("%d ", code[i]);
    }
    printf("\n");
}

Enigma::~Enigma()
{
    if (rotors != nullptr)
    {
        entryWheel.~EntryWheel();
        reflector.~Reflector();
    }
    delete[] rotors;
    rotors = nullptr;
    delete[] message;
    message = nullptr;
    delete[] code;
    code = nullptr;
    rotorsNumber = 0;
}

void Enigma::moveRotors()
{
    int index = rotorsNumber - 1;
    if (index > MAX_MOVING_ROTOR_INDEX)
    {
        index = MAX_MOVING_ROTOR_INDEX;
    }

    for (int j = index; j > 0; j--)
    {
        rotors[j].rotate(rotors[j - 1]);
    }
    rotors[0].setPosition(1); // Move quickest rotor separately.
}

void Enigma::setOneNumber()
{
    int n = message[currrentCodeLength];

#if TEST == true
    printf("Message: %d\n", n);
#endif

    n = entryWheel.findIndexBinary(entryWheel.getBasicAlphabet(), n);

#if TEST == true
    printf("Entry Wheel index: %d\n", n);
#endif

    for (int i = 0; i < rotorsNumber; i++)
    {
        n = rotors[i].characteristicToBasic(n);
    }
    n = reflector.characteristicToBasic(n);
    for (int i = rotorsNumber - 1; i >= 0; i--)
    {
        n = rotors[i].basicToCharacteristic(n);
    }
    n = entryWheel.findElement(entryWheel.getBasicAlphabet(), n);
    code[currrentCodeLength] = n;
    for (int i = rotorsNumber - 1; i > 0; i--)
    {
        rotors[i].setDidImove(false);
    }
    currrentCodeLength++;
}

int Enigma::messageLength(int* message) const
{
    int i = 0;
    for (i = 0; message[i] != 0; i++) {};
    return i;
}