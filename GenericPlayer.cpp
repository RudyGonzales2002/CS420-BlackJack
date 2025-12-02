#include "GenericPlayer.h"

using namespace std;

GenericPlayer::GenericPlayer() {}   // body empty

GenericPlayer::~GenericPlayer() {}  // body empty

void GenericPlayer::setName(string inName)
{
    // store the player's name
    name = inName;
}

string GenericPlayer::getName() const
{
    return name;
}

bool GenericPlayer::isBusted() const
{
    // if total > 21 → busted
    return (getTotal() > 21);
}

bool GenericPlayer::bust()
{
    // print message that player busted
    cout << name << " busts!\n";
    return true;
}

// << OPERATOR OVERLOAD
// prints:  Name    cards...   (total)

ostream& operator<<(ostream& os, const GenericPlayer& gp)
{
    os << gp.getName() << ":\t";

    if (!gp.cardVector.empty()) {
        // Loop through all cards
        for (auto it = gp.cardVector.begin(); it != gp.cardVector.end(); ++it) {
            os << *(*it) << "\t";  // dereference Card* to print
        }

        // Print total if not zero
        if (gp.getTotal() != 0) {
            os << "(" << gp.getTotal() << ")";
        }
    } else {
        // If no cards, print <empty>
        os << "<empty>";
    }

    return os;
}