#pragma once
#include "MechanicalPart.h"

class EntryWheel : public MechanicalPart
{
public:
	EntryWheel();
	EntryWheel(int n);
	EntryWheel(const EntryWheel& orig);
	EntryWheel(EntryWheel&& other);
	EntryWheel& operator=(const EntryWheel& right);
	EntryWheel& operator=(EntryWheel&& right);
	int* getBasicAlphabet() const;
	~EntryWheel();

#if TEST == true
	void print();
#endif

};