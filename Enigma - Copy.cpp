#include "Enigma.h"
#include <iostream>

#define ONE_ROTOR 1
#define TWO_ROTORS 2
#define POSITION_ONE 1

Enigma::Enigma() : entryWheel(EntryWheel()), reflector(Reflector())
{
    rotorsNumber = 0;
    rotors = nullptr;
    message = nullptr;
    messageSize = 0;
    currrentCodeLength = 0;
    code = nullptr;
}

Enigma::Enigma(Repository& repository, int* input) : entryWheel(std::move(repository.entryWheel))
{
    int inputLength = 2 + 2 * input[0];
    rotorsNumber = input[0];
    
#if TEST == true
    printf("PREPARING\n");
    entryWheel.print();
#endif

    rotors = new Rotor[rotorsNumber];
    
    for (int i = 0, j = 1; i < rotorsNumber; i++, j = j + 2)
    {
        rotors[i] = repository.rotors[input[j]];
        rotors[i].setPosition(input[j + 1] - 1);
        rotors[i].setNotch();

#if TEST == true
     //rotors[i].print();
#endif

    }
    rotors[0].setFirstRotor();
    if (rotorsNumber >= 2)
    {
        rotors[1].setSecondRotor();
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

void Enigma::setMessage(int* mess)
{
    messageSize = messageLength(mess);
    message = new int[messageSize];
    for (int i = messageSize - 1; i >= 0; i--)
    {
        message[i] = mess[i];
    }
    code = new int[messageSize];
}

void Enigma::setCode()
{   
    rotateFirstAndSetOneNumber();
    switch (rotorsNumber)
    {
    case ONE_ROTOR:
        for (int i = 0; i < messageSize - 1; i++)
        {
            rotateFirstAndSetOneNumber();
        }
        break;
    case TWO_ROTORS:
        for (int i = 0; i < messageSize - 1; i++)
        {
            rotors[1].rotateSecondRotor(rotors[0]);
            rotateFirstAndSetOneNumber();
        }
        break;
    default:
        for (int i = 0; i < messageSize - 1; i++)
        {
            rotors[2].rotateThirdAndSecondRotor(rotors[1]);
            rotors[1].rotateSecondRotor(rotors[0]);
            rotateFirstAndSetOneNumber();
        }
        break;
    }
    printf("\n");
}

void Enigma::rotateFirstAndSetOneNumber()
{
    rotors[0].rotateSeparately();
    setOneNumber();
}

Enigma::~Enigma()
{
    entryWheel.~EntryWheel();
    reflector.~Reflector();
    delete[] rotors;
    rotors = nullptr;
    delete[] message;
    message = nullptr;
    delete[] code;
    code = nullptr;
}

void Enigma::setOneNumber()
{
    int n = message[currrentCodeLength] - 1;

#if TEST == true
    printf("Message index: %d\n", n);
#endif

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
    n = n + 1;
    printf("%d ", n);
    //code[currrentCodeLength] = n;
    currrentCodeLength++;
}

int Enigma::messageLength(int* mess)
{
    int i = 0;
    for (i = 0; mess[i] != 0; i++) {};
    return i;
}