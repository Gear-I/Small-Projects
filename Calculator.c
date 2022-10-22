// Welcome to a simple calculator


#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    double a, b;
    while (1) {
        printf(" Welcome to the calculator\nEnter an operation of your choice (+, -, *, /), if want to exit press x: ");
        scanf(" %c", &ch);
        // to exit
        if (ch == 'x')
            exit(0);
        printf("Enter two numbers: ");
        scanf("%lf %lf", &a, &b);
        //Different Operations
        if (ch == '+') {
            // For Addition
            printf("%.1lf + %.1lf = %.1lf\n", a, b, a + b);
        }
        else if (ch == '-') {
            // For Subtraction
            printf("%.1lf - %.1lf = %.1lf\n", a, b, a - b);
        }
        else if (ch == '*') {
            // For Multiplication
            printf("%.1lf * %.1lf = %.1lf\n", a, b, a * b);
        }
        else if (ch == '/') {
            // For Division
            printf("%.1lf / %.1lf = %.1lf\n", a, b, a / b);
        }
        else {
            // If operation does not match
            printf("Error! please enter a valid operation\n");
        }
    }
}


