#pragma once
#include "Repository.h"

class Enigma
{
public:
    Enigma();
    Enigma(Repository& repository, int* input);
    ~Enigma();

    void setMessage(int* mess);
    void setCode();

private:
    Rotor* rotors;
    EntryWheel entryWheel;
    Reflector reflector;
    int rotorsNumber;
    int* message;
    int messageSize;
    int currrentCodeLength;
    int* code;

    void rotateFirstAndSetOneNumber();
    void setOneNumber();
    static int messageLength(int* mess);
};