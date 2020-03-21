#pragma once
#include "Tests.h"

class MechanicalPart
{
public:
    int findIndex(int* arr, int element) const;
    int findIndexBinary(int* arr, int element) const;
    int findElement(int* arr, int index) const;
protected:
    int* basicAlphabet;
    int length;
    int* createBasicAlphabet(int n);
    void copy(int* newArr, int* oldArr, int length) const;
    virtual ~MechanicalPart() = 0;
};