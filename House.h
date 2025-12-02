#ifndef HOUSE_H
#define HOUSE_H

#include "GenericPlayer.h"

// House is the dealer (computer)
class House : public GenericPlayer
{
public:
    House(const std::string& name = "Dealer");

    virtual bool isHitting() const;  // house hits on 16 or less

    void flipFirstCard();   // flips over the first card in the hand
};

#endif
