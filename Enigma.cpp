#include <iostream>
#include "Enigma.h"
#define BUFFER_SIZE 100000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int index = 1;
    
    int n = 0;
    int m = 0;
    cin >> n;
    cin >> m;
    Repository repository(n, m);
    int* charAlp = new int[n];
    int buffer[BUFFER_SIZE];

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> charAlp[i];
        }
        repository.addRotor(charAlp);
        
        for (int i = 0;; i++)
        {
            cin >> buffer[i];
            index = buffer[0];
            if (i == index)
            {
                break;
            }
        }
        repository.setRotorTransferPoint(buffer);
    }

    int l = 0;
    cin >> l;
    repository.preparePlaceForReflectors(l);

    for (int i = 0; i < l; i++)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> charAlp[i];
        }
        repository.addReflector(charAlp);
    }
    
    int p = 0;
    cin >> p;
    
    for (int j = 0; j < p; j++)
    {
        index = 1;
        for (int i = 0; i < index; i++)
        {
            cin >> buffer[i];
            index = buffer[0] * 2 + 2;
        }
        Enigma new_enigma{ repository, buffer };
        
        for (int i = 0;; i++)
        {
            cin >> buffer[i];
            if (buffer[i] == 0)
            {
                break;
            }
        }
        new_enigma.setMessage(buffer);
        new_enigma.setCode();
    }
    
    /*
    Repository repository(6, 2);
    int intAlphabet[6] = { 5, 1, 6, 4, 2, 3 };
    int firstAlp[6] = { 2, 1, 5, 6, 3, 4 };
    //int secAlp[4] = { 4, 3, 2, 1 };
    int blabla[6] = { 6, 5, 2, 1, 3, 4 };
   // int anotherblabla[4] = { 4, 3, 1, 2 };
    repository.addRotor(intAlphabet);
    int rotPoint[2] = { 1, 2 };
    repository.setRotorTransferPoint(rotPoint);
    repository.addRotor(blabla);
    repository.setRotorTransferPoint(rotPoint);
 
    repository.preparePlaceForReflectors(1);
    repository.addReflector(firstAlp);
    //repository.addReflector(secAlp);
    //repository.addReflector(intAlphabet);
    int input[8] = { 2, 0, 1, 1, 1, 0 };
    Enigma enigma(repository, input);
    int message[2] = { 5, 0 };
    enigma.setMessage(message);
    printf("Counting starts... \n");
    enigma.setCode();
    int y = 2;
    system("pause");
    */

    return 0;
}