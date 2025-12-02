#ifndef DECK_H
#define DECK_H

#include "Hand.h"
#include "GenericPlayer.h"


// Deck is also a Hand, but with 52 cards and extra operations
class Deck : public Hand
{
public:
    Deck();
    virtual ~Deck() { }   // no extra work needed

    void populate();                          // create standard deck
    void shuffle();                           // shuffle the cards
    void deal(Hand& aHand);                   // deal one card
    void additionalCards(GenericPlayer& gp);  // hit a player as needed
};

#endif
