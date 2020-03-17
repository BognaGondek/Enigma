#include "Rotor.h"
#include <iostream>

//public:

Rotor::Rotor()
{
	basicAlphabet = nullptr;
	characteristicAlphabet = nullptr;
	rotationTransferPoints = nullptr;
	numberOfRotationTransferPoints = 0;
	length = 0;
	firstRotor = false;
	isRatchetUncovered = false;
	didImove = false;
}

Rotor::Rotor(int n, int* characteristicAlphabet)
{
	length = n;
	basicAlphabet = new int[length];
	basicAlphabet = CreateBasicAlphabet(n);
	this->characteristicAlphabet = new int[length];
	for (int i = 0; i < length; i++)
	{
		this->characteristicAlphabet[i] = characteristicAlphabet[i];
	}
	this->rotationTransferPoints = nullptr;
	this->numberOfRotationTransferPoints = 0;
	this->firstRotor = false;
	this->isRatchetUncovered = false;
	didImove = false;
}

Rotor::Rotor(const Rotor& orig)
{
	length = orig.length;
	basicAlphabet = new int[length];
	basicAlphabet = CreateBasicAlphabet(length);
	characteristicAlphabet = new int[length];
	copy(characteristicAlphabet, orig.characteristicAlphabet, length);
	rotationTransferPoints = new int[length];
	numberOfRotationTransferPoints = orig.numberOfRotationTransferPoints;
	copy(rotationTransferPoints, orig.rotationTransferPoints, numberOfRotationTransferPoints);
	firstRotor = orig.firstRotor;
	isRatchetUncovered = orig.isRatchetUncovered;
	didImove = orig.didImove;
}

Rotor& Rotor::operator=(const Rotor& right)
{
	Rotor Rotor = right;
	std::swap(basicAlphabet, Rotor.basicAlphabet);
	std::swap(characteristicAlphabet, Rotor.characteristicAlphabet);
	std::swap(length, Rotor.length);
	std::swap(rotationTransferPoints, Rotor.rotationTransferPoints);
	std::swap(numberOfRotationTransferPoints, Rotor.numberOfRotationTransferPoints);
	std::swap(firstRotor, Rotor.firstRotor);
	std::swap(isRatchetUncovered, Rotor.isRatchetUncovered);
	std::swap(didImove, Rotor.didImove);
	return *this;
}

void Rotor::rotate(Rotor& right)
{
	if (right.isRatchetUncovered)
	{
		if (didImove == false)
		{
			rotateOnePosition();
		}
		if (!right.firstRotor)
		{
			right.rotateOnePosition();
			right.didImove = true;
		}
	}
}

void Rotor::setPosition(int numberOfTimes)
{
	for (int i = 0; i < numberOfTimes; i++)
	{
		rotateOnePosition();
	}
}

int Rotor::CharacteristicToBasic(int index)
{
	int n = FindElement(characteristicAlphabet, index);
	n = FindIndex(basicAlphabet, n);
	return n;
}

int Rotor::BasicToCharacteristic(int index)
{
	int n = FindElement(basicAlphabet, index);
	n = FindIndex(characteristicAlphabet, n);
	return n;
}

void Rotor::SetFirstRotor(bool firstRotor)
{
	this->firstRotor = firstRotor;
}

void Rotor::SetIsRatcherUncovered()
{
	if (wasRotationPointHit())
	{
		isRatchetUncovered = true;
	}
}

void Rotor::SetRotationTransferPoints(int* rotationTransferPoints, int numberOfRotationTransferPoints)
{
	this->numberOfRotationTransferPoints = numberOfRotationTransferPoints;
	if (numberOfRotationTransferPoints != 0)
	{
		this->rotationTransferPoints = new int[numberOfRotationTransferPoints];
		for (int i = 0; i < numberOfRotationTransferPoints; i++)
		{
			int n = rotationTransferPoints[i];
			n = FindIndex(characteristicAlphabet, n);
			if (n == 0)
			{
				n = length - 1;
			}
			else
			{
				n -= 1;
			}
			this->rotationTransferPoints[i] = FindElement(characteristicAlphabet, n);
		}
	}
	else
	{
		rotationTransferPoints = new int[1];
		rotationTransferPoints[0] = { 0 };
	}
}

Rotor::~Rotor()
{
	delete[] basicAlphabet;
	basicAlphabet = nullptr;
	delete[] characteristicAlphabet;
	characteristicAlphabet = nullptr;
	delete[] rotationTransferPoints;
	rotationTransferPoints = nullptr;
	length = 0;
}

#if TEST == true

void Rotor::print()
{
	printf("Rotor\n");
	printf("Basic: ");
	for (int i = 0; i < length; i++)
	{
		printf("%d ", basicAlphabet[i]);
	}
	printf("\n");
	printf("Char: ");
	for (int i = 0; i < length; i++)
	{
		printf("%d ", characteristicAlphabet[i]);
	}
	printf("\n");
	printf("Transfer: ");
	for (int i = 0; i < numberOfRotationTransferPoints; i++)
	{
		printf("%d ", rotationTransferPoints[i]);
	}
	printf("\n");
	printf("ratchet: %d \n", isRatchetUncovered);
	printf("first: %d\n\n", firstRotor);
}

#endif

// private:

bool Rotor::wasRotationPointHit()
{
	for (int i = 0; i < numberOfRotationTransferPoints; i++)
	{
		if (rotationTransferPoints[i] == characteristicAlphabet[0])
		{
			return true;
		}
	}
	return false;
}

void Rotor::rotateOnePosition()
{
	int firstElement = basicAlphabet[0];
	int i = 0;
	
	for (i = 0; i < length - 1; i++)
	{
		basicAlphabet[i] = basicAlphabet[i + 1];
	}
	basicAlphabet[i] = firstElement;

	firstElement = characteristicAlphabet[0];
	i = 0;

	for (i = 0; i < length - 1; i++)
	{
		characteristicAlphabet[i] = characteristicAlphabet[i + 1];
	}
	characteristicAlphabet[i] = firstElement;

	if (isRatchetUncovered == true)
	{
		isRatchetUncovered = false;
	}
	SetIsRatcherUncovered();
}