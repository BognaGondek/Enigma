#include <iostream>
#include "Enigma.h"
#include <vld.h>
#define BUFFER_SIZE 10000
using namespace std;

int main()
{
    int index = 1;

    int n = 0;
    int m = 0;
    scanf_s("%d", &n);
    scanf_s("%d", &m);
    Repository repository(n, m);
    int* charAlp = new int[n];
    int buffer[BUFFER_SIZE];
    
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            scanf_s("%d", &charAlp[i]);
        }
        repository.addRotor(charAlp);
        
        for (int i = 0;; i++)
        {
            scanf_s("%d", &buffer[i]);
            index = buffer[0];
            if (i == index)
            {
                break;
            }
        }
        repository.setRotorTransferPoint(buffer);
    }
    
    
    int l = 0;
    scanf_s("%d", &l);
    repository.preparePlaceForReflectors(l);

    for (int i = 0; i < l; i++)
    {
        for (int i = 0; i < n; i++)
        {
            scanf_s("%d", &charAlp[i]);
        }
        repository.addReflector(charAlp);
    }
    
    int p = 0;
    scanf_s("%d", &p);

    for (int j = 0; j < p; j++)
    {
        index = 1;
        for (int i = 0; i < index; i++)
        {
            scanf_s("%d", &buffer[i]);
            index = buffer[0] * 2 + 2;
        }
        Enigma newEnigma( repository, buffer );
        for (int i = 0;; i++)
        {
            scanf_s("%d", &buffer[i]);
            if (buffer[i] == 0)
            {
                break;
            }
        }
        newEnigma.setMessage(buffer);
        newEnigma.setCode();
    }
    
    delete[] charAlp;
    return 0;
}