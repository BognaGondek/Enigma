#pragma once
#include "MechanicalPart.h"

class Reflector : public MechanicalPart
{
public:
	Reflector();
	Reflector(int n, int* characteristicAlphabet);
	Reflector(const Reflector& orig);
	Reflector(Reflector&& other);
	Reflector& operator=(const Reflector& right);
	Reflector& operator=(Reflector&& right);
	int characteristicToBasic(int index);

#if TEST == true
	void print();
#endif

	~Reflector();
private:
	int* characteristicAlphabet;
};