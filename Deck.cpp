#include "Deck.h"
#include <algorithm>
#include <iostream>

Deck::Deck()
{
    // reserve storage for all 52 cards and then populate
    cardVector.reserve(52);
    populate();
}

void Deck::populate()
{
    // start fresh
    clearHand();

    // two nested loops go through all suits and all ranks
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
    {
        for (int r = Card::ACE; r <= Card::KING; ++r)
        {
            add(new Card(static_cast<Card::RANK>(r),
                         static_cast<Card::SUIT>(s)));
        }
    }
}

void Deck::shuffle()
{
    // random_shuffle works on the vector of pointers
    std::random_shuffle(cardVector.begin(), cardVector.end());
}

void Deck::deal(Hand& aHand)
{
    if (!cardVector.empty())
    {
        aHand.add(cardVector.back());
        cardVector.pop_back();
    }
    else
    {
        std::cout << "Out of cards. Unable to deal." << std::endl;
    }
}

void Deck::additionalCards(GenericPlayer& gp)
{
    // keep dealing as long as player wants a hit and is not busted
    while (!gp.isBusted() && gp.isHitting())
    {
        deal(gp);
        std::cout << gp << std::endl;

        if (gp.isBusted())
        {
            gp.bust();
        }
    }
}

