#include "Reflector.h"
#include <iostream>

Reflector::Reflector()
{
	basicAlphabet = nullptr;
	characteristicAlphabet = nullptr;
	length = 0;
}

Reflector::Reflector(int n, int* characteristicAlphabet)
{
	length = n;
	basicAlphabet = new int[length];
	basicAlphabet = CreateBasicAlphabet(length);
	this->characteristicAlphabet = new int[length];
	for (int i = 0; i < length; i++)
	{
		this->characteristicAlphabet[i] = characteristicAlphabet[i];
	}
}

Reflector::Reflector(const Reflector& orig)
{
	length = orig.length;
	basicAlphabet = new int[length];
	basicAlphabet = CreateBasicAlphabet(length);
	characteristicAlphabet = new int[length];
	for (int i = 0; i < length; i++)
	{
		characteristicAlphabet[i] = orig.characteristicAlphabet[i];
	}
}

Reflector& Reflector::operator=(const Reflector& right)
{
	Reflector reflector = right;
	std::swap(basicAlphabet, reflector.basicAlphabet);
	std::swap(characteristicAlphabet, reflector.characteristicAlphabet);
	std::swap(length, reflector.length);
	return *this;
}

int Reflector::CharacteristicToBasic(int index)
{
	int n = FindElement(characteristicAlphabet, index);
	n = FindIndex(basicAlphabet, n);
	return n;
}

int Reflector::BasicToCharacteristic(int index)
{
	int n = FindElement(basicAlphabet, index);
	n = FindIndex(characteristicAlphabet, n);
	return n;
}

#if TEST == true

void Reflector::print()
{
	printf("Reflector:\n");
	printf("Basic:\n");
	for (int i = 0; i < length; i++)
	{
		printf("%d ", basicAlphabet[i]);
	}
	printf("\nChar:\n");
	for (int i = 0; i < length; i++)
	{
		printf("%d ", characteristicAlphabet[i]);
	}
	printf("\n\n");
}


#endif

Reflector::~Reflector()
{
	length = 0;
	delete[] characteristicAlphabet;
	characteristicAlphabet = nullptr;
	delete[] basicAlphabet;
	basicAlphabet = nullptr;
}