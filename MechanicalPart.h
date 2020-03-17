#pragma once
#include "Tests.h"

class MechanicalPart
{
public:
    int FindIndex(int* arr, int element);
    int FindElement(int* arr, int index);
    int* basicAlphabet;
protected:
    int length;
    int* CreateBasicAlphabet(int n);
    void copy(int* newArr, int* oldArr, int length);
    virtual ~MechanicalPart() = 0;
};