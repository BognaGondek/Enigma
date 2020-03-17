#pragma once
#include "MechanicalPart.h"

class Reflector : public MechanicalPart
{
public:
	Reflector();
	Reflector(int n, int* characteristicAlphabet);
	Reflector(const Reflector& orig);
	Reflector& operator=(const Reflector& right);
	int CharacteristicToBasic(int index);
	int BasicToCharacteristic(int index);
#if TEST == true
	void print();
#endif

	~Reflector();
private:
	int* characteristicAlphabet;
};