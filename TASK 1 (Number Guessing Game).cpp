#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int num, guess, attempts = 0;
    char playAgain;
    srand(time(0));

    do {
        num = 1 + rand() % 100;
        attempts = 0;

        cout << "\n*** WELCOME TO THE NUMBER CHASE ***\n\n";
        cout << "I have selected a random number between 1 and 100.\n";
        cout << "Your challenge is to guess the number!\n";
        cout << "LET'S BEGIN THE GAME!\n";

        do {
            cout << endl << "Enter your guess: ";
            cin >> guess;
            attempts++;

            if (guess > num) {
                cout << "Your guess is high.\n";
            } else if (guess < num) {
                cout << "Your guess is low.\n";
            } else {
                cout << "\nCongratulations! You guessed it RIGHT!!!\n";
                cout << "You took " << attempts << " attempts to guess the number.\n\n";
                break;
            }

        } while (true);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\n\nThank you for playing the number chase!\n\n";
    return 0;
}
