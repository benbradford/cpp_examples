#include "Vehicle.h"
#include "Property.h"
#include "Cards.h"
#include "Dealer.h"
#include <iostream>

using namespace std;

int main() {

	Vehicle motorBike;			// calls default constructor ( no arguments) 
	Vehicle car(4, 1500, 120);	// calls constructor taking 3 arguments


	Property bungalow;
	Property house(2, 4);


	Cards cards;
	Dealer dealer(cards); // dealer must be supplied a reference to Cards

	dealer.shuffle();

	for (unsigned int i = 0; i < 52; ++i) {

		cout << cards.get_card(i).face << cards.get_card(i).suit << endl;
	}
	return 0;
}