#pragma once
#include "MechanicalPart.h"

class Rotor : public MechanicalPart
{
public:
	bool didImove;
	Rotor();
	Rotor(int n, int* characteristicAlphabet);
	Rotor(const Rotor& orig);
	Rotor& operator=(const Rotor& right);
	void rotate(Rotor& right);
	void setPosition(int numberOfTimes);
	int CharacteristicToBasic(int index);
	int BasicToCharacteristic(int index);
	void SetFirstRotor(bool firstRotor);
	void SetIsRatcherUncovered();
	void SetRotationTransferPoints(int* rotationTransferPoints, int numberOfRotationTransferPoints);
	~Rotor();

#if TEST == true
	void print();
#endif

private:
	int* characteristicAlphabet;
	int* rotationTransferPoints;
	int numberOfRotationTransferPoints;
	bool firstRotor;
	bool isRatchetUncovered;

	bool wasRotationPointHit();
	void rotateOnePosition();
};