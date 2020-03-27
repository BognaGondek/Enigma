#pragma once
#include "MechanicalPart.h"

class Rotor : public MechanicalPart
{
public:
	Rotor();
	Rotor(int n, int* characteristicAlphabet);
	Rotor(const Rotor& orig);
	Rotor(Rotor&& other);
	Rotor& operator=(const Rotor& right);
	Rotor& operator=(Rotor&& right);

	void rotate(Rotor& right);
	int characteristicToBasic(int index);
	int basicToCharacteristic(int index);
	
	void setPosition(int numberOfTimes);
	void setFirstRotor(bool firstRotor);
	void setIsRatcherUncovered();
	void setRotationTransferPoints(int* rotationTransferPoints);
	void setDidImove(bool didImove);

	~Rotor();

#if TEST == true
	void print();
#endif
	
	bool secondRotor = false;
	bool secMov = false;
private:
	int numberOfRotations;
	int* characteristicAlphabet;
	int* rotationTransferPoints;
	int numberOfRotationTransferPoints;
	bool firstRotor;
	bool isRatchetUncovered;
	bool didImove;

	bool wasRotationPointHit() const;
	void rotateOnePosition();
	void setRotationTransferPoint(int index, int element);
};