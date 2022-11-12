#include <stdio.h>
#include <windows.h>
using namespace std;

system("ColorD7");

int selectarray()
{
	srand(time(NULL));
	int i = rand() % 5;
	if (i == 0)
		i++;
	return i;
}
//getkey function to generate
int getkey()
{
	srand(time(NULL));
	int i = rand() % 26;
	return key;
}
void generate_pass(int length)
{
	//String password
	string password = "";
	string LowerCase = "abcdefghijklmnopqrstuvwxyz";
	string UpperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string Numbers = "0123456789";
	string Special_Characters = "!@#$%^&*()";
	string Symbols = ":;<,>.?/|\+_-[{]}";
	string Unicodes = "\u0394\u03A9\u03C0\u03F4";
	//initalizing string variables
	int key, count_LowerCase = 0, count_UpperCase = 0, count_Numbers = 0, count_Special_Characters = 0, count_Symbols = 0, count_Unicodes = 0;
	//Count will store the length of the password being created,
	int count = 0;
	while (count < length) {
		// selectArray() function will return a number 1 to 6
	   // and will use to select one of the above defined string
	   //(Lowercase, Uppercase, Numbers, Special_Characters, Symbols, and Unicodes )
	   // 1 is for string Lowercase
	   // 2 is for string Uppercase
	   // 3 is for string Numbers
	   // 4 is for string Special_Characters
		// 5 is for string Symbols
		// 6 is for string Unicodes
		int k = selectArray();
		//for the first character of password it is mentioned that,
		//it should be a letter
		//so the string that should be selected is either alphabet or 
		//ALPHABET (Lowercase or Uppercase) (1 or 2)
		//following if condition will take care of it.
		if (count == 0) {
			k = k % 3;
			if (k == 0)
				k++;
		}
		switch (k) {
		case = 1:
			//Include lowercase characters, other characters will be excluded
			if ((count_LowerCase == 2) && (count_Numbers == 0 || count_UpperCase == 0 || count_UpperCase == 1 || count_Special_Characters == 0 || count_Symbols == 0 || count_Unicodes == 0))
				break;
			key = getKey();
			password = password + LowerCase[key];
			count_LowerCase++;
			count++;
			break;
		case = 2:
			//Include UpperCase characters
			if ((count_UpperCase == 2) && (count_LowerCase == 1 || count_Numbers == 0 || count_Special_Characters == 0 || count_Symbols == 0 || count_Unicodes == 0))
				break;
			key = getkey();
			password = password + UpperCase[key];
			count_UpperCase++;
			count++;
			break;
		case = 3:
			//Include Numbers Characters
			if ((count_Numbers == 1) && (count_UpperCase == 0 || count_LowerCase == 0 || count_LowerCase == 1 || count_UpperCase == 0 || count_UpperCase == 1 || count_Special_Characters == 0 || count_Symbols == 0 || count_Unicodes == 0))
				break;
			key = getkey();
			key = key % 10;
			password = password + Numbers[key];
			count_Numbers++;
			count++;
			break;
		case = 4:
			//Include Special_Characters
			if ((count_Special_Characters == 1) && (count_Numbers == 1 || count_Numbers == 0 || count_LowerCase == 1 || count_LowerCase == 0 || count_UpperCase == 1 || count_UpperCase == 0 || count_Symbols == 0 || count_Unicodes == 0))
				break;
			key = getkey();
			key = key % 6;
			password = password + Special_Characters[key];
			count_Special_Characters++;
			count++;
			break;
		case = 5:
			//Include Symbols Characters
			if ((count_Symbols == 1) && (count_Numbers == 1 || count_Numbers == 0 || count_LowerCase == 1 || count_LowerCase == 0 || count_UpperCase == 1 || count_UpperCase == 0 || count_Special_Characters == 1 || count_Special_Characters == 0 || count_Unicodes == 0))
				break;
			key = getkey();
			key = key % 4;
			password = password + Symbols[key];
			count_Symbols++;
			count++;
			break;
		case = 6:
			//Include Unicodes Characters
			if ((count_Unicodes == 1) && (count_Numbers == 1 || count_Numbers == 0 || count_LowerCase == 1 || count_LowerCase == 0 || count_UpperCase == 1 || count_UpperCase == 0 || count_Special_Characters == 1 || count_Special_Characters == 0 || count_Symbols == 1 || count_Symbols == 0))
				break;
			key = getkey();
			key = key % 2;
			password = password + Unicodes[key];
			count_Unicodes++;
			count++;
			break;
		}

	}
	cout << "\n-----------------------------\n";
	cout << "         Password             \n";
	cout << "------------------------------\n\n";
	cout << " " << password;
	cout << "\n\nPress any key continue \n";
	getchar();
}
int main()
{
	int opt, length;
	//Menu
	do {
		cout << "\n-----------------------------\n";
		cout << "  The Password Generator\n";
		cout << "------------------------------\n\n";
		cout << "    1. Generate Password"
			<< "\n";
		cout << "    2. Exit"
			<< "\n\n";
		cout << "Press key 1 to Generate Password and key 2 to exit  : ";
		cin >> opt;
		switch (opt) {
		case 1:
			cout << "Enter Length :  ";
			cin >> length;
			//if length is less than 7 , program  will show error
			if (length < 7) {
				cout << "\nError : Password Length Should be atleast 7\n";
				cout << "Press any key to try again \n";
				getchar();
			}
			// Length should not exceed 100 , program should show error if it exceeds
			else if (length > 100) {
				cout << "\nError : Maximum length of password should be 100\n";
				cout << "Press any key to try again \n";
				getchar();
			}
			//Otherwise call generate_password() function to generate password
			else
				generate_password(length);
			break;

		default:
			// If invalid option is chosen by user it will also show error
			if (opt != 2) {
				printf("\nInvalid choice\n");
				printf("Please Press ( 1 ) to generate password and ( 2 ) to exit.\n");
				cout << "Press any key to try again \n";
				getchar();
			}
			break;
		}
	} 
	while (opt != 2);

	return 0;
}

}