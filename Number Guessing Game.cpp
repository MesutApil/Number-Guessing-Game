// Author Name: Mesut Apil
// Number Guessing Game
// 3-digit Number Guessing Game!

#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

void displayHeader(); // This function displays the header
void displayFooter(); // This function displays the footer
void validateHints(int,int,int,int,int,int); // This function returns Appropriate letter

int main(){

    char playAgain = 'y'; // variable to check if the user wants to play again

    displayHeader();

    while (playAgain == 'y' || playAgain == 'Y'){

        int randNum1 = rand() % 2 +1, // Random digit one created by computer
            randNum2 = rand() % 2 +5 , // Random digit two created by computer
            randNum3 = rand ()% 2 +8; //  Random digit three created by the computer

        int tries = 0, // number tries user has tried to guess the number
            guess = 1; // This is to display the guess number to the user on the output

        int userInput, // This is the variable to use the user input
        userDigit1, // This is digit one of the user input
        userDigit2, // This is digit two of the user input
        userDigit3; // This is digit number 3 of the user input

        bool correct_answer = false; // Variable changes if the answer is correct and jumps out of the loop

        cout << randNum1 << randNum2 << randNum3 << endl; // To display rand digit to ensure the digits are not repeating

        do{
            cout << "please Enter a 3 digit number: " ;
            cin >> userInput;

            while (cin.fail() || userInput > 999){

                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Please enter in a valid 3 digit number: ";
                cin >> userInput;
            }

            userDigit1 = userInput/100;
            userDigit2 = (userInput/10) %10;
            userDigit3 = userInput%10;

            cout << "Player Guess #" << guess << ": " << userDigit1 << userDigit2 << userDigit3 << endl;

            validateHints(userDigit1,userDigit2,userDigit3,randNum1,randNum2,randNum3);

            tries++;
            guess++;

            cout << endl;

            if (userDigit1 == randNum1 && userDigit2 == randNum2 && userDigit3 == randNum3){

                cout << "CONGRATS! YOU GUESSED ALL 3 of the DIGITS CORRECTLY!" << endl << endl;
                correct_answer = true;
                cout << "Would you like to play again? Y/y or n/N ";
                cin >> playAgain;
                cout << endl << endl;

                while (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N' ){

                    cout << "Invalid entry! please enter Y/y or n/N ";
                    cin.clear(); // clear +1input buffer to restore cin to a usable state
                    cin.ignore(INT_MAX, '\n'); // ignore last input
                    cin >> playAgain;
                }
            }

            if (tries == 10 ){

                cout << "You are out of tries! The correct number is: "
                     << randNum1 << randNum2 << randNum3 << "!";
                cout << " Would you like to play again? Y/y or n/N ";
                 cin >> playAgain;

                while (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N' ){

                    cout << "Invalid entry! please enter Y/y or n/N ";
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cin >> playAgain;
                }
            }

        }while (tries < 10 && correct_answer == false);

        tries = 0;

    }

    displayFooter();

    return 0;
}
//*****************************************************************
// Displays the header message at the beginning of the game.
//******************************************************************

void displayHeader(){
   cout << "Welcome to my game! \n"
        << "I am thinking of a 3-digit number. Try to guess what it is. You will have 10 tries!"
        << "\nHere are some clues: \nWhen I say 'B' it means no digit is correct."
        << "\nWhen I say 'P' that means one digit is correct but in the wrong position."
        << "\nWhen I say 'F' One digit is correct and in the right position." << endl << endl;
}

//*****************************************************************
// Displays the footer message at the end of the game.
//*******************************************************************
void displayFooter(){
   cout << "\n\nImplemented by Mesut Apil \n"
        << "2 - 06 - 2019" << endl << endl;
}

//*****************************************************************
// displays appropriate letter hint depending on user input
// userDigit1 is the first digit of user guess.
// userDigit2 is the second digit of user guess
// userDigit3 is the third digit of user guess
// randNum1 first digit of random number generated by computer
// randNum2 second digit of random number generated by computer
// randNum3 second digit of urandom number generated by computer
//*******************************************************************

void validateHints(int userDigit1, int userDigit2, int userDigit3, int randNum1,
                    int randNum2, int randNum3){

    if( userDigit1 == randNum1){           //Checks to print out "F"

        cout<< "F";
    }
    else if(userDigit1 == randNum2|| userDigit1 == randNum3){  //Checks to print out "P"

        cout<< "P";
    }
    if(userDigit2 == randNum2){           //Checks to print out "F"

        cout<< "F";
    }

    else if(userDigit2== randNum1 || userDigit2 == randNum3){  //Checks to print out "P"

        cout<< "P";
    }

    if(userDigit3 == randNum3){            //Checks to print out "F"

        cout<< "F";
    }

    else if(userDigit3 == randNum1 || userDigit3 == randNum2){  //Checks to print out "P"

        cout<< "P";
    }

    if (userDigit1 != randNum1 && userDigit1 != randNum2 && userDigit1 != randNum3
        && userDigit2 != randNum1 && userDigit2 != randNum2 && userDigit2 != randNum3
        && userDigit3 != randNum1 && userDigit3 != randNum2 && userDigit3 != randNum3){  //If not number is alike, prints out "B"

        cout << "B";
    }
}

