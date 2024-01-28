#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int randomNumber = rand() % 100 + 1;

    cout << "Welcome to the Guess the Number game!\nTry to guess the number between 1 and 100.\n";

    int userGuess;
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess == randomNumber) {
            cout << "Congratulations! You guessed the correct number.\n";
        } else if (userGuess > randomNumber) {
            cout << "Too high! Try again.\n";
        } else {
            cout << "Too low! Try again.\n";
        }

    } while (userGuess != randomNumber);

    return 0;
}
