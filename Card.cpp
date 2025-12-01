#include "Card.h"

int Card::getValue() const
{
    // if the card is face down we don't know its value
    if (!faceUp)
    {
        return 0;
    }

    int value = 0;

    // 2–9 are their face value, 10/J/Q/K are all 10, Ace is 1 here
    if (rank >= TEN)
    {
        value = 10;
    }
    else
    {
        value = static_cast<int>(rank);
    }

    return value;
}

void Card::flip()
{
    // simple toggle of the bool flag
    faceUp = !faceUp;
}

std::ostream& operator<<(std::ostream& out, const Card& aCard)
{
    // these arrays are used as look-up tables for printing cards
    static const std::string RANKS[] =
    {
        "0", "A", "2", "3", "4", "5", "6",
        "7", "8", "9", "10", "J", "Q", "K"
    };

    static const std::string SUITS[] = { "C", "D", "H", "S" };

    if (aCard.faceUp)
    {
        out << RANKS[aCard.rank] << SUITS[aCard.suit];
    }
    else
    {
        out << "XX";    // hidden card
    }

    return out;
}

