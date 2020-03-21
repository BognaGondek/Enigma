#pragma once
#include "EntryWheel.h"
#include "Rotor.h"
#include "Reflector.h"

class Repository
{
public:
    EntryWheel entryWheel;
    Rotor* rotors;
    Reflector* reflectors;
    int alphabetLength;
    int rotorsNumber;
    int reflectorsNumber;

    Repository();
    Repository(int n, int m);
    void addRotor(int* characteristicAlphabet);
    void setRotorTransferPoint(int* rotationTransferPoints);
    void preparePlaceForReflectors(int l);
    void addReflector(int* characteristicAlphabet);
    ~Repository();
};