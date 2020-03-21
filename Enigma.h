#pragma once
#include "Repository.h"

class Enigma
{
public:
    Enigma();
    Enigma(Repository& repository, int* input);
    void setMessage(int* message);
    void setCode();
    ~Enigma();

private:
    Rotor* rotors;
    EntryWheel entryWheel;
    Reflector reflector;
    int rotorsNumber;
    int* message;
    int messageSize;
    int currrentCodeLength;
    int* code;

    void moveRotors();
    void setOneNumber();
    int messageLength(int* message) const;
};