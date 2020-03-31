#pragma once
#include "EntryWheel.h"
#include "Rotor.h"
#include "Reflector.h"

class Repository
{
public:
    int alphabetLength;
    int rotorsNumber;
    int reflectorsNumber;
    EntryWheel entryWheel;
    Rotor* rotors;
    Reflector* reflectors;

    Repository();
    Repository(int n, int m);
    ~Repository();

    void addRotor(int* characteristicAlphabet);
    void setRotorTransferPoint(int* rotationTransferPoints);
    void preparePlaceForReflectors(int l);
    void addReflector(int* characteristicAlphabet);
};