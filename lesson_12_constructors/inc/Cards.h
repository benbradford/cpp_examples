#pragma once

#include "Card.h"

class Cards {
public:

	Cards(); // specifying a default constructor so we can initialise each Card in mCards

	Card& get_card(unsigned int index);
	void swap(unsigned int index1, unsigned int index2);
private:

	Card mCards[52]; // creates 52 Card objects with undefined face+suit values
};