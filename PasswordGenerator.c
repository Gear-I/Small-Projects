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