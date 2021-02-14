#include "Rotor.h"
#include <iostream>

void Rotor::rotateSecondRotor(Rotor& first)
{
    if (first.isNotchUncovered && didIRotate == false)
    {
        rotateSeparately();
        didIMoveOnceAlready = true;
    }
    didIRotate = false;
}

void Rotor::rotateThirdAndSecondRotor(Rotor& second)
{
    if (second.isNotchUncovered && second.didIMoveOnceAlready == true)
    {
        rotateSeparately();
        second.rotateSeparately();
        second.didIRotate = true;
    }
}

void Rotor::rotateSeparately()
{
    numberOfRotations++;
    numberOfRotations = numberOfRotations % length;
    setNotch();
}

int Rotor::characteristicToBasic(int index) const
{
    int trueIndex = index + numberOfRotations;
    trueIndex = trueIndex % length;
    trueIndex = characteristicAlphabet[trueIndex] - 1;
    trueIndex = trueIndex - numberOfRotations;

    if (trueIndex < 0)
    {
        trueIndex += length;
    }
    return trueIndex;
}

int Rotor::basicToCharacteristic(int index)
{
    int trueIndex = index + numberOfRotations;
    trueIndex = trueIndex % length;
    trueIndex = permuAlphabet[trueIndex];

    trueIndex = trueIndex - numberOfRotations;
    if (trueIndex < 0)
    {
        trueIndex += length;
    }
    return trueIndex;
}

void Rotor::setFirstRotor()
{
    firstRotor = true;
    didIMoveOnceAlready = true;
}

void Rotor::setSecondRotor()
{
    this->secondRotor = true;
}


void Rotor::setNotch()
{
    for (int i = 0; i < numberOfRotationTransferPoints; i++)
    {
        if (rotationTransferPoints[i] == numberOfRotations)
        {
            isNotchUncovered = true;
            return;
        }
    }
    isNotchUncovered = false;
}


void Rotor::setRotationTransferPoints(int* rotTraPoint)
{
    numberOfRotationTransferPoints = rotTraPoint[0];
    if (numberOfRotationTransferPoints != 0)
    {
        rotationTransferPoints = new int[numberOfRotationTransferPoints];
        for (int i = 1; i <= numberOfRotationTransferPoints; i++)
        {
            setRotationTransferPoint(i - 1, rotTraPoint[i]);
        }
    }
    else
    {
        rotationTransferPoints = new int[1];
        rotationTransferPoints[0] = { -1 };
    }
}

void Rotor::setRotationTransferPoint(int index, int element)
{
    int n = element - 1;
    if (n != 0)
    {
        n = n - 1;
    }
    else
    {
        n = length - 1;
    }
    rotationTransferPoints[index] = n;
}

void Rotor::setPosition(int position)
{
    numberOfRotations = position;
}