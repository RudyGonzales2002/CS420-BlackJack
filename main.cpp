#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

int main() {

    // Greet the player
    cout << "Welcome to Blackjack!\n";

    // Ask for the player's name
    string name;
    cout << "Enter your name: ";
    cin >> name;

    Game game(name);

    // Variable to control the play-again loop
    char again = 'y';

    // Main game loop: repeats until the player chooses not to play
    while (again == 'y' || again == 'Y') {

        // Play one round of Blackjack
        game.play();

        // Ask the player if they want to play another round
        cout << "Do you want to play again? (y/n): ";
        cin >> again;

        while (again != 'y' && again != 'Y' && again != 'n' && again != 'N') {
            cout << "Please enter 'y' or 'n': ";
            cin >> again;
        }
    }

    cout << "Thanks for playing!\n";

    return 0;
}
