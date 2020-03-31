#include "Rotor.h"
#include <iostream>

void Rotor::initVar()
{
	firstRotor = false;
	secondRotor = false;
	didIMoveOnceAlready = false;
	isNotchUncovered = false;
	didIRotate = false;
	numberOfRotations = 0;
	numberOfRotationTransferPoints = 0;
	rotationTransferPoints = nullptr;
}

Rotor::Rotor()
{
	basicAlphabet = nullptr;
	characteristicAlphabet = nullptr;
	length = 0;
	initVar();
}

Rotor::Rotor(int n, int* characteristicAlphabet)
{
	length = n;
	basicAlphabet = createBasicAlphabet(n);
	this->characteristicAlphabet = new int[length];
	for (int i = 0; i < length; i++)
	{
		this->characteristicAlphabet[i] = characteristicAlphabet[i];
	}
	initVar();
}

Rotor::Rotor(const Rotor& orig)
{
	length = orig.length;
	numberOfRotations = orig.numberOfRotations;
	numberOfRotationTransferPoints = orig.numberOfRotationTransferPoints;
	basicAlphabet = createBasicAlphabet(length);
	characteristicAlphabet = new int[length];
	copy(characteristicAlphabet, orig.characteristicAlphabet, length);
	rotationTransferPoints = new int[numberOfRotationTransferPoints];
	copy(rotationTransferPoints, orig.rotationTransferPoints, numberOfRotationTransferPoints);
	firstRotor = orig.firstRotor;
	secondRotor = orig.secondRotor;
	didIRotate = orig.didIRotate;
	didIMoveOnceAlready = orig.didIRotate;
	isNotchUncovered = orig.isNotchUncovered;
}

Rotor::Rotor(Rotor&& orig)
{
	length = orig.length;
	numberOfRotations = orig.numberOfRotations;
	numberOfRotationTransferPoints = orig.numberOfRotationTransferPoints;
	basicAlphabet = createBasicAlphabet(length);
	characteristicAlphabet = new int[length];
	copy(characteristicAlphabet, orig.characteristicAlphabet, length);
	rotationTransferPoints = new int[numberOfRotationTransferPoints];
	copy(rotationTransferPoints, orig.rotationTransferPoints, numberOfRotationTransferPoints);
	firstRotor = orig.firstRotor;
	secondRotor = orig.secondRotor;
	didIRotate = orig.didIRotate;
	didIMoveOnceAlready = false;
	isNotchUncovered = orig.isNotchUncovered;
	
	orig.basicAlphabet = nullptr;
	orig.characteristicAlphabet = nullptr;
	orig.rotationTransferPoints = nullptr;
}

Rotor& Rotor::operator=(const Rotor& right)
{
	Rotor rotor = right;
	std::swap(length, rotor.length);
	std::swap(numberOfRotations, rotor.numberOfRotations);
	std::swap(numberOfRotationTransferPoints, rotor.numberOfRotationTransferPoints);
	std::swap(basicAlphabet, rotor.basicAlphabet);
	std::swap(characteristicAlphabet, rotor.characteristicAlphabet);
	std::swap(rotationTransferPoints, rotor.rotationTransferPoints);
	std::swap(firstRotor, rotor.firstRotor);
	std::swap(secondRotor, rotor.secondRotor);
	std::swap(didIMoveOnceAlready, rotor.didIMoveOnceAlready);
	std::swap(didIRotate, rotor.didIRotate);
	std::swap(isNotchUncovered, rotor.isNotchUncovered);
	return *this;
}

Rotor& Rotor::operator=(Rotor&& right)
{
	std::swap(length, right.length);
	std::swap(numberOfRotations, right.numberOfRotations);
	std::swap(numberOfRotationTransferPoints, right.numberOfRotationTransferPoints);
	std::swap(basicAlphabet, right.basicAlphabet);
	std::swap(characteristicAlphabet, right.characteristicAlphabet);
	std::swap(rotationTransferPoints, right.rotationTransferPoints);
	std::swap(firstRotor, right.firstRotor);
	std::swap(secondRotor, right.secondRotor);
	std::swap(didIMoveOnceAlready, right.didIMoveOnceAlready);
	std::swap(didIRotate, right.didIRotate);
	std::swap(isNotchUncovered, right.isNotchUncovered);
	return *this;
}

Rotor::~Rotor()
{
	delete[] basicAlphabet;
	basicAlphabet = nullptr;
	delete[] characteristicAlphabet;
	characteristicAlphabet = nullptr;
	delete[] rotationTransferPoints;
	rotationTransferPoints = nullptr;
}