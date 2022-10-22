// Welcome to a simple calculator
#include <stdio.h>
#include <stdlib.h>
printf("Welcome to a simple calculator");

int main()

{
	char ch;
	double a, b;
	while (1) {
		printf("Enter an opertion either, (+, -, *, /), if want to exit press x: ")
			scanf("%c", &ch);
		//To Exit
		if (ch == 'x')
			exit(0);
		printf("Enter first and second number: ");
		scanf("%lf %lf", &a, &b);
		//Different Operations Options
		//Addition
		if (ch == '+') {
			printf(" % .1lf + % .1lf = % .1lf\n", a, b, a + b); 
		}
		//Subtraction
		else if (ch == '-') {
			printf("%.1lf - %.1lf = %.1lf\n", a, b, a - b);
		}
		//Multiplcation
		else if (ch == '*') {
			printf("%.1lf * %.1lf = %.1lf\n", a, b, a * b);
		}
		//Division 
		else if (ch == '/') {
			printf("%.1lf / %.1lf = %.1lf\n", a, b, a / b);
		}
		else {
			// If operator doesn't match any case constant
			printf("Error! Enter a valid operator\n");

		}

		}

		}
