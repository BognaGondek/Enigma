#pragma once
#include "MechanicalPart.h"

class Rotor : public MechanicalPart
{
public:
    Rotor();
    Rotor(int n, int* characteristicAlphabet);
    Rotor(const Rotor& orig);
    Rotor(Rotor&& orig);
    Rotor& operator=(const Rotor& right);
    Rotor& operator=(Rotor&& right);
    ~Rotor();

    void rotateSecondRotor(Rotor& first);
    void rotateThirdAndSecondRotor(Rotor& second);
    int characteristicToBasic(int index) const;
    int basicToCharacteristic(int index);

    void setPosition(int position);
    void rotateSeparately();
    void setFirstRotor();
    void setSecondRotor();
    void setNotch();
    void setRotationTransferPoints(int* rotTraPoint);

    bool didIMoveOnceAlready;
    bool didIRotate;
private:
    int numberOfRotations;
    int* characteristicAlphabet;
    int* permuAlphabet;
    int* rotationTransferPoints;
    int numberOfRotationTransferPoints;
    bool firstRotor;
    bool secondRotor;
    bool isNotchUncovered;

    int* findPerm();
    void initVar();
    void setRotationTransferPoint(int index, int element);
};