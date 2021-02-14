#pragma once

class MechanicalPart
{
public:
    int findIndex(int* arr, int element) const;
protected:
    int* basicAlphabet;
    int length;
    int* createBasicAlphabet(int n);
    static void copy(int* newArr, int* oldArr, int len);
    virtual ~MechanicalPart() = 0;
};