#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Deck.h"
#include "House.h"
#include <string>
using namespace std;

class Game {
    private:
    Deck deck;
    House house;
    Player player;

    public:
    Game(const string& name);
    virtual ~Game();
    void play();
};


#endif