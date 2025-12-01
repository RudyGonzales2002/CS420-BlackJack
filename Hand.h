#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

// Hand represents a collection of card pointers
class Hand
{
protected:
    std::vector<Card*> cardVector;

public:
    Hand();
    virtual ~Hand();

    void add(Card* cardPtr);   // add a card to the hand
    void clearHand();          // delete all cards in the hand
    int getTotal() const;      // compute total value of the hand
};

#endif
