#include "MechanicalPart.h"
#include <iostream>
#include "Tests.h"

int MechanicalPart::findIndex(int* arr, int element) const
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

int MechanicalPart::findIndexBinary(int* arr, int element) const
{
    int min = 0;
    int max = length;
    int middle = 0;

    while (min <= max)
    {
        middle = (min + max) / 2;

        if (arr[middle] == element)
        {
            return middle;
        }
        else if (arr[middle] < element)
        {
            min = middle + 1;
        }
        else
        {
            max = middle - 1;
        }
    }

    return -1;
}

int MechanicalPart::findElement(int* arr, int index) const
{
    return arr[index];
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

void MechanicalPart::copy(int* newArr, int* oldArr, int length) const
{
    for (int i = 0; i < length; i++)
    {
        newArr[i] = oldArr[i]; 
    }
}

MechanicalPart::~MechanicalPart() {};