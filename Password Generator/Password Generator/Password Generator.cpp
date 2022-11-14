// Password Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdlib.h>
#include <stdio.h>
#include<time.h>
int main()
{
    int i, password, len;
    srand((unsigned int)time(NULL));
    printf("Enter Password Length and must be greater than 5\n");
    scanf("%d", &len);
    if (len >= 5)
    {
        for (i = 0; i < len; i++)
        {
            int k = rand() % 128;
            if ((k >= 48 && k <= 57) || (k >= 65 && k <= 90) || (k >= 97 && k <= 122) || (k >= 35 && k <= 37) || k == 64)
            {
                printf("%c", k);
            }
            else
            {
                i--;
            }
        }
        printf("\n");
    }
    else
    {
        printf("Length should be greater than 5\n");
    }
    return(0);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
