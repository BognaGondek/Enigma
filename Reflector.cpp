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
	basicAlphabet = createBasicAlphabet(length);
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
	basicAlphabet = createBasicAlphabet(length);
	characteristicAlphabet = new int[length];
	for (int i = 0; i < length; i++)
	{
		characteristicAlphabet[i] = orig.characteristicAlphabet[i];
	}
}

Reflector::Reflector(Reflector&& other)
{
	length = other.length;
	basicAlphabet = new int[length];
	basicAlphabet = createBasicAlphabet(length);
	characteristicAlphabet = new int[length];
	for (int i = 0; i < length; i++)
	{
		characteristicAlphabet[i] = other.characteristicAlphabet[i];
	}
	other.basicAlphabet = nullptr;
	other.characteristicAlphabet = nullptr;
	other.length = 0;
}

Reflector& Reflector::operator=(const Reflector& right)
{
	Reflector reflector = right;
	std::swap(basicAlphabet, reflector.basicAlphabet);
	std::swap(characteristicAlphabet, reflector.characteristicAlphabet);
	std::swap(length, reflector.length);
	return *this;
}

Reflector& Reflector::operator=(Reflector&& right)
{
	std::swap(basicAlphabet, right.basicAlphabet);
	std::swap(characteristicAlphabet, right.characteristicAlphabet);
	std::swap(length, right.length);
	return *this;
}

int Reflector::characteristicToBasic(int index)
{
	int n = findElement(characteristicAlphabet, index);

#if TEST == true
	printf(" Reflector:\n found element: %d\n", n);
#endif

	n = findIndexBinary(basicAlphabet, n);

#if TEST == true
	printf("Index: %d\n\n", n);
#endif

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