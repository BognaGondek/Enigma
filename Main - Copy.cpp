#include <iostream>
#include "Enigma.h"
//#include <vld.h>
#define BUFFER_SIZE 100000
using namespace std;

int main()
{
    int alphabetLength = 0;
    int rotorsNumber = 0;
    scanf_s("%d", &alphabetLength);
    scanf_s("%d", &rotorsNumber);
    
    Repository repository(alphabetLength, rotorsNumber);
    
    int* charAlp = new int[alphabetLength]; // characteristic alphabet
    int buffer[BUFFER_SIZE];
    int index = 1;
    int i = 0;

    while(rotorsNumber != 0)
    {
        for (i = 0; i < alphabetLength; i++)
        {
            scanf_s("%d", &charAlp[i]);
        }
        repository.addRotor(charAlp);
        
        for (i = 0;; i++)
        {
            scanf_s("%d", &buffer[i]);
            index = buffer[0];
            if (i == index)
            {
                break;
            }
        }
        repository.setRotorTransferPoint(buffer);
        rotorsNumber--;
    }
    
    int reflectorsNumber = 0;
    scanf_s("%d", &reflectorsNumber);
    repository.preparePlaceForReflectors(reflectorsNumber);
    while(reflectorsNumber != 0)
    {
        for (i = 0; i < alphabetLength; i++)
        {
            scanf_s("%d", &charAlp[i]);
        }
        repository.addReflector(charAlp);
        reflectorsNumber--;
    }
    
    int taskNumber = 0;
    scanf_s("%d", &taskNumber);
    while(taskNumber != 0)
    {
        index = 1;
        for (i = 0; i < index; i++)
        {
            scanf_s("%d", &buffer[i]);
            index = buffer[0] * 2 + 2;
        }
        Enigma newEnigma( repository, buffer );
        for (i = 0;; i++)
        {
            scanf_s("%d", &buffer[i]);
            if (buffer[i] == 0)
            {
                break;
            }
        }
        newEnigma.setMessage(buffer);
        newEnigma.setCode();
        taskNumber--;
    }
    
    delete[] charAlp;
    return 0;
}