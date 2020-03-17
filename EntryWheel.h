#pragma once
#include "MechanicalPart.h"

class EntryWheel : public MechanicalPart
{
public:
	EntryWheel();
	EntryWheel(int n);
	EntryWheel(const EntryWheel& orig);
	EntryWheel& operator=(const EntryWheel& right);
	int* GetBasicAlphabet() const
	{
		return basicAlphabet;
	}
	~EntryWheel();
#if TEST == true
	void print();
#endif
};