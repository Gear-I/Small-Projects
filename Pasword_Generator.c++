#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

//selectArray is  a utility function that is used to
//randomly generate an integer in the range 1 to 4 (both inclusive)
int selectArray()
{
    srand(time(NULL));
    int i = rand() % 5;
    if (i == 0)
        i++;
    return i;
}
//getKey() is another utility function that is used to randomly generate
//an integer in the range 0 to 25 (both inclusive)
int getKey()
{
    srand(time(NULL));

    int key = rand() % 26;
    return key;
}
void generate_password(int length)
{
    //Initializing result string password as NULL.
    string password = "";

    //Strings whose characters will be used to build a password
    string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string s_symbol = "!@#$%&";
    string number = "0123456789";

    //initializing local variables
    int key, count_alphabet = 0, count_ALPHABET = 0, count_number = 0, count_s_symbol = 0;

    //Count will store the length of the password being created,
    //initially this will be zero(0)
    int count = 0;
    while (count < length) {
        // selectArray() function will return a number 1 to 4
        // and will use to select one of the above-defined string
        //(i.e alphabet or ALPHABET or s_symbol or number )
        // 1 is for the string alphabet
        // 2 is for string ALPHABET
        // 3 is for string number
        // and 4 is for string s_symbol

        int k = selectArray();

        //for the first character of the password it is mentioned that,
        //it should be a letter
        //so the string that should be selected is either alphabet or 
        //ALPHABET (i.e 1 or 2)
        //following if condition will take care of it.
        if (count == 0) {
            k = k % 3;
            if (k == 0)
                k++;
        }

        switch (k) {
        case 1:
            // following if condition will check if the minimum requirement of the alphabet
            // character has been fulfilled or not
            // in case it has been fulfilled and the minimum requirements of other
            // characters are still left then it will break ;
            if ((count_alphabet == 2) && (count_number == 0 || count_ALPHABET == 0 || count_ALPHABET == 1 || count_s_symbol == 0))
                break;

            key = getKey();
            password = password + alphabet[key];
            count_alphabet++;
            count++;
            break;

        case 2:
            // following if condition will check if the minimum requirement of
            // ALPHABET character has been fulfilled or not
            // in case it has been fulfilled and the minimum requirements of
            // other characters are still left then it will break ;
            if ((count_ALPHABET == 2) && (count_number == 0 || count_alphabet == 0 || count_alphabet == 1 || count_s_symbol == 0))
                break;
            key = getKey();
            password = password + ALPHABET[key];
            count_ALPHABET++;
            count++;
            break;

        case 3:
            // following if condition will check if the minimum requirement
            // of Numbers  has been fulfilled or not
            // in case it has been fulfilled and the minimum requirements of
            // other characters are still left then it will break ;
            if ((count_number == 1) && (count_alphabet == 0 || count_alphabet == 1 || count_ALPHABET == 1 || count_ALPHABET == 0 || count_s_symbol == 0))
                break;

            key = getKey();
            key = key % 10;
            password = password + number[key];
            count_number++;
            count++;
            break;

        case 4:
            // following if condition will check if the minimum requirement of
            // Special symbol character has been fulfilled or not
            // in case it has been fulfilled and the minimum requirements of
            // other characters are still left then it will break ;
            if ((count_s_symbol == 1) && (count_alphabet == 0 || count_alphabet == 1 || count_ALPHABET == 0 || count_ALPHABET == 1 || count_number == 0))
                break;

            key = getKey();
            key = key % 6;
            password = password + s_symbol[key];
            count_s_symbol++;
            count++;
            break;
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
            cout << "  Random Password Generator\n";
            cout << "------------------------------\n\n";
            cout << "    1. Generate Password"
                << "\n";
            cout << "    2. Exit"
                << "\n\n";
            cout << "Press key 1 to Generate Password and key 2 to exit: ";
            cin >> opt;

            switch (opt) {
            case 1:
                cout << "Enter Length:  ";
                cin >> length;
                //if the length is less than 7, the program  will show an error
                if (length < 7) {
                    cout << "\nError: Password Length Should be at least 7\n";
                    cout << "Press any key to try again \n";
                    getchar();
                }
                // Length should not exceed 100, the program should show an error if it exceeds
                else if (length > 100) {
                    cout << "\nError: Maximum length of password should be 100\n";
                    cout << "Press any key to try again \n";
                    getchar();
                }
                //Otherwise call generate_password() function to generate password
                else
                    generate_password(length);
                break;

            default:
                // If an invalid option is chosen by the user it will also show an error
                if (opt != 2) {
                    cout << "\nInvalid choice\n";
                    cout << "Please Press ( 1 ) to generate password and ( 2 ) to exit.\n";
                    cout << "Press any key to try again \n";
                    getchar();
                }
                break;
            }
        } while (opt != 2);

        return 0;
    }