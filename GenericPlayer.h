#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include "Hand.h"
#include <string>
#include <iostream>

using namespace std;


class GenericPlayer : public Hand
{
private:
    string name;

public:
    GenericPlayer();
    virtual ~GenericPlayer();

    void setName(string inName);
    string getName() const;

    virtual bool isHitting() const = 0; // PURE VIRTUAL

    bool isBusted() const;   // returns true if total > 21
    bool bust();             // prints name + bust message

    // overloaded << operator
    friend ostream& operator<<(std::ostream& os, const GenericPlayer& gp);

};


#endif