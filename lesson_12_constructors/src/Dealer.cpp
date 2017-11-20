#include "Dealer.h"
#include <cstdlib> // for rand()

Dealer::Dealer(Cards& cards)
	: mCards(cards) {} // we must take a reference to cards in the constructor, so mCards can be assigned to something

void Dealer::shuffle() {

	for (unsigned int i = 0; i < 52; ++i) {

		unsigned int swapWith = int((int)rand() % 52-i) + i;
		mCards.swap(i, swapWith);
	}
}
