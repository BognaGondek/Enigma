#pragma once
#include "Repository.h"

class Enigma
{
public:
    Enigma();
    Enigma(Repository& repository, int* input);
    Enigma(const Enigma& orig);
    Enigma& operator=(const Enigma& right);
    void SetMessage(int* message);
    void SetCode();
    ~Enigma();
private:
    EntryWheel entryWheel;
    Reflector reflector;
    int rotorsNumber;
    Rotor* rotors;
    Repository repository;
    int* message;
    int messageSize;
    int currrentCodeLength;
    int* code;

    void SetOneNumber();
    int messageLength(int* message);
};