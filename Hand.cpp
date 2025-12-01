#include "Hand.h"

Hand::Hand()
{
    // reserve space for up to 7 cards as asked in the spec
    cardVector.reserve(7);
}

Hand::~Hand()
{
    // destructor reuses clearHand()
    clearHand();
}

void Hand::add(Card* cardPtr)
{
    cardVector.push_back(cardPtr);
}

void Hand::clearHand()
{
    // free all heap-allocated Card objects
    std::vector<Card*>::iterator iter;
    for (iter = cardVector.begin(); iter != cardVector.end(); ++iter)
    {
        delete *iter;
        *iter = NULL;
    }

    cardVector.clear();
}

int Hand::getTotal() const
{
    // empty hand has total 0
    if (cardVector.empty())
    {
        return 0;
    }

    // if first card is face down its value will be 0, so we return 0
    if (cardVector[0]->getValue() == 0)
    {
        return 0;
    }

    int total = 0;

    // add up values of all cards
    std::vector<Card*>::const_iterator iter;
    for (iter = cardVector.begin(); iter != cardVector.end(); ++iter)
    {
        total += (*iter)->getValue();
    }

    // check if the hand contains at least one Ace
    bool containsAce = false;
    for (iter = cardVector.begin(); iter != cardVector.end(); ++iter)
    {
        // Ace was counted as 1 in getValue()
        if ((*iter)->getValue() == 1)
        {
            containsAce = true;
            break;
        }
    }

    // if we have an Ace and still safe to add 10, treat Ace as 11
    if (containsAce && total <= 11)
    {
        total += 10;
    }

    return total;
}

