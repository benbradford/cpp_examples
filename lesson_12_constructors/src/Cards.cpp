#include "Cards.h"

Cards::Cards() {

	// mCards will have undefined / uninitialised values
	// give values now

	char suits[] = {'h', 's', 'd', 'c'};
	char faces[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};
	
	unsigned int cardCount = 0;

	for (unsigned int suit = 0; suit < 4; ++suit) {
		for (unsigned int face = 0; face <13; ++face) {
			
			mCards[cardCount].suit = suits[suit];
			mCards[cardCount].face = faces[face];
			++cardCount;
		}
	}
}

Card& Cards::get_card(unsigned int index) {

	return mCards[index];
}

void Cards::swap(unsigned int index1, unsigned int index2) {

	Card temp = mCards[index1];
	mCards[index1] = mCards[index2];
	mCards[index2] = temp;
}