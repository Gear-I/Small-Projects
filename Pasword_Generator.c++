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
			if ((count_Numbers == 1) && (count_UpperCase == 0 || count_LowerCase == 0 || count_LowerCase == 1 || count_UpperCase == 0 || count_UpperCase == 1 || count_Special_Characters == 0 || count_Symbols == 0 || count_Unicodes == 0))
				break;
			key = getkey();
			key = key % 10;
			password = password + Numbers[key];
			count_Numbers++;
			count++;
			break;

}