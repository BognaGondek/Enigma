#include "Enigma.h"
#include <iostream>

Enigma::Enigma()
{
    entryWheel = EntryWheel();
    reflector = Reflector();
    rotorsNumber = 0;
    rotors = nullptr;
    repository = Repository();
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
            rotors[i].SetFirstRotor(true);
        }
        rotors[i].SetIsRatcherUncovered();

#if TEST == true
        rotors[i].print();
        printf("PREP\n");
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

Enigma::Enigma(const Enigma& orig)
{
    entryWheel = orig.entryWheel;
    reflector = orig.reflector;
    rotorsNumber = orig.rotorsNumber;
    rotors = orig.rotors;
    repository = orig.repository;
    message = orig.message;
    messageSize = orig.messageSize;
    currrentCodeLength = orig.currrentCodeLength;
    code = orig.code;
}

Enigma& Enigma::operator=(const Enigma& right)
{
    Enigma enigma = right;
    std::swap(entryWheel, enigma.entryWheel);
    std::swap(reflector, enigma.reflector);
    std::swap(rotorsNumber, enigma.rotorsNumber);
    std::swap(rotors, enigma.rotors);
    std::swap(repository, enigma.repository);
    std::swap(message, enigma.message);
    std::swap(messageSize, enigma.messageSize);
    std::swap(currrentCodeLength, enigma.currrentCodeLength);
    std::swap(code, enigma.code);
    return *this;
}

void Enigma::SetMessage(int* message)
{
    messageSize = messageLength(message);
    this->message = new int[messageSize];
    for (int i = 0; i < messageSize; i++)
    {
        this->message[i] = message[i];
    }
    code = new int[messageSize];
}

void Enigma::SetCode()
{   
    for (int i = 0; i < messageSize; i++)
    {
        SetOneNumber();
        printf("%d\n", i);
        rotors[0].print();
        //rotors[1].print();
        //rotors[2].print();
        printf("\n");
    }
    for (int i = 0; i < currrentCodeLength; i++)
    {
        printf("%d ", code[i]);
    }
}

Enigma::~Enigma()
{
    entryWheel.~EntryWheel();
    reflector.~Reflector();
    delete[] rotors;
    rotors = nullptr;
    delete message;
    message = nullptr;
    delete code;
    code = nullptr;
}

void Enigma::SetOneNumber()
{
    for (int i = rotorsNumber - 1; i > 0; i--)
    {
        rotors[i].rotate(rotors[i-1]);
    }
    rotors[0].setPosition(1);

    int n = message[currrentCodeLength];
    n = entryWheel.FindIndex(entryWheel.GetBasicAlphabet(), n);
    for (int i = 0; i < rotorsNumber; i++)
    {
        n = rotors[i].CharacteristicToBasic(n);
    }
    n = reflector.BasicToCharacteristic(n);
    for (int i = rotorsNumber - 1; i >= 0; i--)
    {
        n = rotors[i].BasicToCharacteristic(n);
    }
    n = entryWheel.FindElement(entryWheel.GetBasicAlphabet(), n);
    code[currrentCodeLength] = n;
    currrentCodeLength++;

    for (int i = rotorsNumber - 1; i > 0; i--)
    {
        rotors[i].didImove = false;
    }

}

int Enigma::messageLength(int* message)
{
    int i = 0;
    for (i = 0; message[i] != 0; i++)
    {
        i++;
    }
    return i;
}