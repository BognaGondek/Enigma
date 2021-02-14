#include "MechanicalPart.h"
#include <iostream>

int MechanicalPart::findIndex(int* arr, int element) const
{
    for (int i = length - 1;; i--)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
}

int* MechanicalPart::createBasicAlphabet(int n)
{
    int* newBasicAlphabet = new int[n];
    for (int i = 0; i < n; i++)
    {
        newBasicAlphabet[i] = i + 1;
    }
    return newBasicAlphabet;
}

void MechanicalPart::copy(int* newArr, int* oldArr, int len)
{
    for (int i = 0; i < len; i++)
    {
        newArr[i] = oldArr[i];
    }
}

MechanicalPart::~MechanicalPart() {};