#include "Game.h"
#include <ostream>
#include <string>
using namespace std;

Game::Game(const string &name) : player(name) {
    deck.populate();
    deck.shuffle();
}

Game::~Game() {}


void Game::play() {

    for (int i = 0; i < 2; i++) {
        deck.deal(player);
        deck.deal(house);
    }

    house.flipFirstCard();

    cout << player << "\n";
    cout << house << "\n";

    deck.additionalCards(player);

    house.flipFirstCard();

    cout << house << "\n";

    deck.additionalCards(house);

    if (house.isBusted()) {
        if (!player.isBusted()) {
            player.win();
        }
    } else {
        if (!player.isBusted()) {
            if (player.getTotal() > house.getTotal()) {
                player.win();
            } else if (player.getTotal() < house.getTotal()) {
                player.lose();
            } else {
                player.push();  // tie
            }
        }
    }

    player.clearHand();
    house.clearHand();

}




