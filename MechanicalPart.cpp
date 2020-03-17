#include "MechanicalPart.h"
#include <iostream>
#include "Tests.h"

int MechanicalPart::FindIndex(int* arr, int element)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int MechanicalPart::FindElement(int* arr, int index)
{
    return arr[index];
}

int* MechanicalPart::CreateBasicAlphabet(int n)
{
    int* newBasicAlphabet = new int[n];
    for (int i = 0; i < n; i++)
    {
        newBasicAlphabet[i] = i + 1;
    }
    return newBasicAlphabet;
}

void MechanicalPart::copy(int* newArr, int* oldArr, int length)
{
    for (int i = 0; i < length; i++)
    {
        newArr[i] = oldArr[i]; 
    }
}

MechanicalPart::~MechanicalPart() {};