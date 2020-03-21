#include "EntryWheel.h"
#include <iostream>
#include <initializer_list>

EntryWheel::EntryWheel() { basicAlphabet = nullptr;	length = 0; };

EntryWheel::EntryWheel(int n)
{ 
	length = n;
	basicAlphabet = new int[length];
	basicAlphabet = createBasicAlphabet(n); 
};

EntryWheel::EntryWheel(const EntryWheel& orig)
{
	length = orig.length;
	basicAlphabet = new int[length];
	basicAlphabet = createBasicAlphabet(orig.length);
}

EntryWheel::EntryWheel(EntryWheel&& other)
{
	length = other.length;
	basicAlphabet = new int[length];
	basicAlphabet = createBasicAlphabet(length);
	other.length = 0;
	other.basicAlphabet = nullptr;
}

EntryWheel& EntryWheel::operator=(const EntryWheel& right)
{
	EntryWheel tmp = right;
	std::swap(basicAlphabet, tmp.basicAlphabet);
	std::swap(length, tmp.length);
	return *this;
}

EntryWheel& EntryWheel::operator=(EntryWheel&& right)
{
	std::swap(basicAlphabet, right.basicAlphabet);
	std::swap(length, right.length);
	return *this;
}

int* EntryWheel::getBasicAlphabet() const
{
	return basicAlphabet;
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