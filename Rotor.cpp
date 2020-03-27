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
	numberOfRotations = 0;
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
	this->rotationTransferPoints = nullptr;
	this->numberOfRotationTransferPoints = 0;
	this->firstRotor = false;
	this->isRatchetUncovered = false;
	didImove = false;
	numberOfRotations = 0;
}

Rotor::Rotor(const Rotor& orig)
{
	length = orig.length;
	basicAlphabet = createBasicAlphabet(length);
	characteristicAlphabet = new int[length];
	copy(characteristicAlphabet, orig.characteristicAlphabet, length);
	rotationTransferPoints = new int[length];
	numberOfRotationTransferPoints = orig.numberOfRotationTransferPoints;
	copy(rotationTransferPoints, orig.rotationTransferPoints, numberOfRotationTransferPoints);
	firstRotor = orig.firstRotor;
	isRatchetUncovered = orig.isRatchetUncovered;
	didImove = orig.didImove;
	numberOfRotations = orig.numberOfRotations;
}

Rotor::Rotor(Rotor&& other)
{
	length = other.length;
	basicAlphabet = createBasicAlphabet(length);
	characteristicAlphabet = new int[length];
	copy(characteristicAlphabet, other.characteristicAlphabet, length);
	rotationTransferPoints = new int[length];
	numberOfRotationTransferPoints = other.numberOfRotationTransferPoints;
	copy(rotationTransferPoints, other.rotationTransferPoints, numberOfRotationTransferPoints);
	firstRotor = other.firstRotor;
	isRatchetUncovered = other.isRatchetUncovered;
	didImove = other.didImove;
	other.basicAlphabet = nullptr;
	other.characteristicAlphabet = nullptr;
	other.rotationTransferPoints = nullptr;
	numberOfRotations = other.numberOfRotations;
}

Rotor& Rotor::operator=(const Rotor& right)
{
	Rotor rotor = right;
	std::swap(basicAlphabet, rotor.basicAlphabet);
	std::swap(characteristicAlphabet, rotor.characteristicAlphabet);
	std::swap(length, rotor.length);
	std::swap(rotationTransferPoints, rotor.rotationTransferPoints);
	std::swap(numberOfRotationTransferPoints, rotor.numberOfRotationTransferPoints);
	std::swap(firstRotor, rotor.firstRotor);
	std::swap(isRatchetUncovered, rotor.isRatchetUncovered);
	std::swap(didImove, rotor.didImove);
	std::swap(numberOfRotations, rotor.numberOfRotations);
	return *this;
}

Rotor& Rotor::operator=(Rotor&& right)
{
	std::swap(basicAlphabet, right.basicAlphabet);
	std::swap(characteristicAlphabet, right.characteristicAlphabet);
	std::swap(length, right.length);
	std::swap(rotationTransferPoints, right.rotationTransferPoints);
	std::swap(numberOfRotationTransferPoints, right.numberOfRotationTransferPoints);
	std::swap(firstRotor, right.firstRotor);
	std::swap(isRatchetUncovered, right.isRatchetUncovered);
	std::swap(didImove, right.didImove);
	std::swap(numberOfRotations, right.numberOfRotations);
	return *this;
}

void Rotor::rotate(Rotor& right)
{
	if (right.isRatchetUncovered)
	{
		if (this->didImove == false)
		{
			if ((right.secondRotor && right.secMov == true)|| right.firstRotor)
			{
				rotateOnePosition();
			}
			/* this->didImove = true; */
		}
		if (!right.firstRotor && right.secMov == true)
		{
			right.rotateOnePosition();
			right.didImove = true;
		}
	}
}

int Rotor::characteristicToBasic(int index)
{
	int trueIndex = index + numberOfRotations;
	while(trueIndex >= length)
	{
		trueIndex -= length;
	}
	int n = findElement(characteristicAlphabet, trueIndex);

#if TEST == true
	printf("true index %d\n", trueIndex);
	printf("Element under index: %d\n", n);
#endif

	n = findIndexBinary(basicAlphabet, n);

#if TEST == true
	printf("Index in basic: %d\n", n);
#endif
	trueIndex = n - numberOfRotations;
	while (trueIndex < 0)
	{
		trueIndex += length;
	}
	//printf("true index %d\n\n", trueIndex);
	return trueIndex;
}

int Rotor::basicToCharacteristic(int index)
{
	int trueIndex = index + numberOfRotations;
	while (trueIndex >= length)
	{
		trueIndex -= length;
	}
	int n = findElement(basicAlphabet, trueIndex);

#if TEST == true

	printf("true index %d\n", trueIndex);
	printf("Element in basic: %d\n", n);
#endif

	n = findIndex(characteristicAlphabet, n);

#if TEST == true
	printf("Characteristic index: %d\n", n);
#endif
	
	trueIndex = n - numberOfRotations;
	while (trueIndex < 0)
	{
		trueIndex += length;
	}

	//printf("true index %d\n\n", trueIndex);
	return trueIndex;
}

void Rotor::setPosition(int numberOfTimes)
{
	for (int i = 0; i < numberOfTimes; i++)
	{
		rotateOnePosition();
	}
}

void Rotor::setFirstRotor(bool firstRotor)
{
	this->firstRotor = firstRotor;
}

void Rotor::setIsRatcherUncovered()
{
	if (wasRotationPointHit())
	{
		isRatchetUncovered = true;
	}
}

void Rotor::setRotationTransferPoints(int* rotationTransferPoints)
{
	this->numberOfRotationTransferPoints = rotationTransferPoints[0];
	if (numberOfRotationTransferPoints != 0)
	{
		this->rotationTransferPoints = new int[numberOfRotationTransferPoints];
		for (int i = 1; i <= numberOfRotationTransferPoints; i++)
		{
			setRotationTransferPoint(i, rotationTransferPoints[i]);
		}
	}
	else
	{
		rotationTransferPoints = new int[1];
		rotationTransferPoints[0] = { -303 };
	}
}

void Rotor::setDidImove(bool didImove)
{
	this->didImove = didImove;
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
	printf("first: %d\n", firstRotor);
	printf("Number of Rot: %d\n\n", numberOfRotations);
}
#endif

// private:

bool Rotor::wasRotationPointHit() const
{
	for (int i = 0; i < numberOfRotationTransferPoints; i++)
	{
		if (rotationTransferPoints[i] == numberOfRotations)
		{
			return true;
		}
	}
	return false;
}

void Rotor::rotateOnePosition()
{
	numberOfRotations += 1;
	if (numberOfRotations >= length)
	{
		while (numberOfRotations >= length)
		{
			numberOfRotations -= length;
			if (numberOfRotations == length)
			{
				numberOfRotations = 0;
			}
		}
		
	}

	if (secondRotor == true)
	{
		secMov = true;
	}

	if (isRatchetUncovered == true)
	{
		isRatchetUncovered = false;
	}
	setIsRatcherUncovered();
}

void Rotor::setRotationTransferPoint(int index, int element)
{
	int n = element;
	n = findIndexBinary(basicAlphabet, n);
	if (n == 0)
	{
		n = length - 1;
	}
	else
	{
		n -= 1;
	}
	rotationTransferPoints[index - 1] = n;
}
