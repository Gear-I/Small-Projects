// Welcome to a simple calculator


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>


    //Text and Background color
system("Color D7");

int main(int argc, char* argv[]) {
    int num1, num2;
    float ans;
    char operators;
    int i = 0, j = 0;
    char s[100] = " ";
    char s1[100], s2[100];


    if (argc == 4) {
        sscanf(argv[1], "%d", &num1);
        sscanf(argv[2], "%c", &operator);
        sscanf(argv[3], "%d", &num2);
        switch (operators) {
        case '+': a = num1 + num2;
            printf("%d %c %d = %.2f\n", num1, operator, num2, a);
            break;
        case '-': a = num1 - num2;
            printf("%d %c %d = %.2f\n", num1, operator, num2, a);
            break;
        case 'x': a = num1 * num2;
            printf("%d %c %d = %.2f\n", num1, operator, num2, a);
            break;
        case '/': a = num1 / num2;
            printf("%d %c %d = %.2f\n", num1, operator, num2, a);
            break;
        case '^': a = num1 ^ num2;
            printf("%d %c %d = %.2f\n", num1, operator, num2, a);
            break;
        case '/': if (num2 == 0) {
            printf("Error! Division by Zero!\n");
        }
                else {
            a = num1 / num2
                if (argc == 3) {
                    sscanf(argv[1], "%c", &operator);
                    sscanf(argv[2], "%d", &num1);
                    switch (operator) {
                    case 'n':
                    case 'N': ans = -num1;
                        printf("-(%d) = %.2f\n", num1, ans);
                        break;
                    case 'a':
                    case 'A': ans = fabs(num1);
                        printf("|%d| = %.2f\n", num1, ans);
                        break;


                    case 's':
                    case 'S': if (num1 < 0) {
                        printf("Can't find square root of negative number\n");
                    }
                            else {
                        ans = sqrt(num1);
                        printf("Sqrt(%d) = %.2f\n", num1, ans);
                    }
                            break;
                    default: printf("%c is not a valid operator!\n", operator);
                    }
                }
                else if ((argc != 3) || (argc != 4)) {

                    printf("Enter the string you want to calculate: ");
                    fgets(s, sizeof(s), stdin);
                    sscanf(s, "%d %c %d", &num1, &operator, &num2);




                    while (s[i] != '\0') {

                        s[i] = argv[1];

                        i++;

                    }

                    while
                        (s[i] != '\0') {

                        s[i] = argv[2];

                        i++;

                    }
                    while
                        (s[i] != '\0') {

                        s[i] = argv[3];

                        i++;

                    }
                }

        }
    else
        printf("Input Error!!!\n");

        }
           

    


