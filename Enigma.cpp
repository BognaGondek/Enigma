#include <iostream>
#include "Enigma.h"
#define BUFFER_SIZE 100

int main()
{
    std::cout << "Oh god\n";
    
    int buffer[BUFFER_SIZE];
    int n = (int)(getchar() - '0');
    int m = (int)(getchar() - '0');
    Repository repository(4, 4);
    
    int* characteristicAlphabet = new int[n];
    char character = ' ';
    int index = 0;
    int numberOfRotationPoints = 0;

    for (int i = 0; i < 2*m; i++)
    {
        if (i % 2 == 0)
        {
            while ((character = getchar()) != '\n')
            {
                characteristicAlphabet[index] = (int)(character - '0');
                index++;
            }
            repository.addRotor(characteristicAlphabet);
            index = 0;
        }
        else
        {
            int* rotationPoints = nullptr;
            while ((character = getchar()) != '\n')
            {
                if (index == 0)
                {
                    numberOfRotationPoints = (int)(character - '0');
                    if (numberOfRotationPoints != 0)
                    {
                        rotationPoints = new int[numberOfRotationPoints];
                    }
                }
                else
                {
                    rotationPoints[index] = (int)(character - '0');
                }
                index++;
            }
            repository.setRotorTransferPoint(numberOfRotationPoints, rotationPoints);
            delete[] rotationPoints;
            index = 0;
        }

        int l = (int)(getchar() - '0');
        repository.preparePlaceForReflectors(l);
        for (int i = 0; i < l; i++)
        {
            while ((character = getchar()) != '\n')
            {
                characteristicAlphabet[index] = (int)(character - '0');
                index++;
            }
            repository.addReflector(characteristicAlphabet);
        }
    }

    int p = (int)(getchar() - '0');
    Enigma* enigmasArray = new Enigma[p];

    for (int i = 0; i < p; i++)
    {
        index = 0;
        while ((character = getchar()) != '\n')
        {
            buffer[index] = (int)(character - '0');
            index++;
        }
        enigmasArray[i] = Enigma(repository, );
    }

    /*
    int intAlphabet[4] = { 1,2,4,3 };
    int firstAlp[4] = { 2, 1 , 4, 3 };
    int secAlp[4] = { 4, 3, 2, 1 };
    int blabla[4] = { 3, 2, 1, 4 };
    int anotherblabla[4] = { 4, 3, 1, 2 };
    repository.addRotor(intAlphabet);
    int rotPoint[1] = { 2 };
    repository.setRotorTransferPoint(1, rotPoint);
    repository.addRotor(blabla);
    repository.setRotorTransferPoint(0, nullptr);
    repository.addRotor(anotherblabla);
    repository.setRotorTransferPoint(0, nullptr);
    repository.addRotor(blabla);
    repository.setRotorTransferPoint(0, nullptr);

    repository.preparePlaceForReflectors(3);
    repository.addReflector(firstAlp);
    repository.addReflector(secAlp);
    repository.addReflector(intAlphabet);
    int input[8] = { 2, 0, 4, 0, 1, 0 };
    Enigma enigma(repository, input);
    int message[33] = { 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4,  1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 0 };
    enigma.SetMessage(message);
    printf("Counting starts... \n");
    enigma.SetCode();
    system("pause");
    */
}