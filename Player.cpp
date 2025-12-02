#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(const string& name)
{
    // Set the player's name.
    setName(name);
}

Player::~Player() {}  // empty

bool Player::isHitting() const {
    // Ask the player if they want another card.
    cout << getName() << " do you want to hit? y/n\n";
    char answer;
    cin >> answer;
    return answer == 'y' || answer == 'Y';
}

bool Player::win() const {
    // Announce that the player has won.
    cout << getName() << " wins!\n";
    return true;
}

bool Player::lose() const {
    // Announce that the player has lost.
    cout << getName() << " loses.\n";
    return true;
}

bool Player::push() const {
    // Announce that the player tied with the dealer.
    cout << getName() << " pushes.\n";
    return true;
}
