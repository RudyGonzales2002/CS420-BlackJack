#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card
{
public:
    // rank and suit enums used throughout the program
    enum RANK { ACE = 1, TWO, THREE, FOUR, FIVE, SIX,
                SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    enum SUIT { CLUBS, DIAMONDS, HEARTS, SPADES };

private:
    RANK rank;
    SUIT suit;
    bool faceUp;

public:
    // constructor uses member initializer list as required
    Card(RANK r, SUIT s, bool isUp = true)
        : rank(r), suit(s), faceUp(isUp)
    {
        // body intentionally empty
    }

    int getValue() const;    // returns value of the card
    void flip();             // flips face up/down

    // overloaded insertion operator for printing a card
    friend std::ostream& operator<<(std::ostream& out, const Card& aCard);
};

#endif