#include "EntryWheel.h"
#include <iostream>
#include <initializer_list>

EntryWheel::EntryWheel() { basicAlphabet = nullptr;	length = 0; };

EntryWheel::EntryWheel(int n) 
{ 
	length = n;
	basicAlphabet = new int[length];
	basicAlphabet = CreateBasicAlphabet(n); 
};

EntryWheel::EntryWheel(const EntryWheel& orig)
{
	length = orig.length;
	basicAlphabet = new int[length];
	basicAlphabet = CreateBasicAlphabet(orig.length);
}

EntryWheel& EntryWheel::operator=(const EntryWheel& right)
{
	EntryWheel tmp = right;
	std::swap(basicAlphabet, tmp.basicAlphabet);
	std::swap(length, tmp.length);
	return *this;
}

EntryWheel::~EntryWheel()
{
	delete[] basicAlphabet;
	basicAlphabet = nullptr;
	length = 0;
}

#if TEST == true

void EntryWheel::print()
{
	printf("entryWheel:\n");
	for (int i = 0; i < length; i++)
	{
		printf("%d ", basicAlphabet[i]);
	}
	printf("\n\n");
}

#endif