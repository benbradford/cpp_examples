#pragma once

#include "Cards.h"

class Dealer {
public:
	Dealer(Cards& cards); // must take a reference to Cards, otherwise we can never initialise it

	void shuffle();
private:
	Cards& mCards; // references must be assigned to something
};