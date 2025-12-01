#include "House.h"
#include <iostream>

House::House(const std::string& name)
    : GenericPlayer(name)
{
    // base constructor already handles name
}

bool House::isHitting() const
{
    if (getTotal() <= 16)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void House::flipFirstCard()
{
    if (!cardVector.empty())
    {
        cardVector[0]->flip();
    }
    else
    {
        std::cout << "House: no cards to flip." << std::endl;
    }
}

