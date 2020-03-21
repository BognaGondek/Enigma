#include "Repository.h"
#include <iostream>
Repository::Repository()
{
    alphabetLength = 0;
    entryWheel = EntryWheel();
    rotors = nullptr;
    reflectors = nullptr;
    rotorsNumber = 0;
    reflectorsNumber = 0;
}

Repository::Repository(int n, int m)
{
    alphabetLength = n;
    entryWheel = EntryWheel(n);
    rotors = new Rotor[m];
    reflectors = nullptr;
    rotorsNumber = 0;
    reflectorsNumber = 0;
}

void Repository::addRotor(int* characteristicAlphabet)
{
    rotors[rotorsNumber] = Rotor(alphabetLength, characteristicAlphabet);
}

void Repository::setRotorTransferPoint(int* rotationTransferPoints)
{
    rotors[rotorsNumber].setRotationTransferPoints(rotationTransferPoints);
    rotorsNumber++;
}

void Repository::preparePlaceForReflectors(int l)
{
    reflectors = new Reflector[l];
}

void Repository::addReflector(int* characteristicAlphabet)
{
    reflectors[reflectorsNumber] = Reflector(alphabetLength, characteristicAlphabet);
    reflectorsNumber++;
}

Repository::~Repository()
{
    entryWheel.~EntryWheel();
    delete[] rotors;
    rotors = nullptr;
    delete[] reflectors;
    reflectors = nullptr;
    alphabetLength = 0;
    rotorsNumber = 0;
    reflectorsNumber = 0;

}