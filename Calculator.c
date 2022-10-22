// Welcome to a simple calculator


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    char ch;
    double a, b;
    while (1) {
        textcolor(RED);
        cprintf(" Welcome to the calculator\nEnter an operation of your choice (+, -, *, /), if want to exit press x: ");
        scanf(" %c", &ch);
        // to exit
        if (ch == 'x')
            exit(0);
        cprintf("Enter two numbers: ");
        scanf("%lf %lf", &a, &b);
        //Different Operations
        if (ch == '+') {
            // For Addition
            cprintf("%.1lf + %.1lf = %.1lf\n", a, b, a + b);
        }
        else if (ch == '-') {
            // For Subtraction
            cprintf("%.1lf - %.1lf = %.1lf\n", a, b, a - b);
        }
        else if (ch == '*') {
            // For Multiplication
            cprintf("%.1lf * %.1lf = %.1lf\n", a, b, a * b);
        }
        else if (ch == '/') {
            // For Division
            cprintf("%.1lf / %.1lf = %.1lf\n", a, b, a / b);
        }
        else {
            // If operation does not match
            cprintf("Error! please enter a valid operation\n");
            getch()
                return 0;
        }
    }
}


