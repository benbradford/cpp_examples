#include "Vehicle.h"
#include "Property.h"
#include "Cards.h"
#include "Dealer.h"
#include <iostream>

using namespace std;

void vehicles() {

	Vehicle motorBike;			// calls default constructor ( no arguments) 
	Vehicle car(4, 1500, 120);	// calls constructor taking 3 arguments

	cout << " a motorBike has " 
			<< motorBike.number_of_wheels() << " wheels, " 
			<< motorBike.engine_cc() << "cc and a top speed of "
			<< motorBike.top_speed() << "mph" << endl;

	cout << " a car has " 
			<< car.number_of_wheels() << " wheels, " 
			<< car.engine_cc() << "cc and a top speed of "
			<< car.top_speed() << "mph" << endl;
}

void properties() {

	Property bungalow;
	Property house(2, 4);
}


void cards() {

	Cards cards;
	Dealer dealer(cards); // dealer must be supplied a reference to Cards

	dealer.shuffle();

	for (unsigned int i = 0; i < 52; ++i) {

		cout << cards.get_card(i).face << cards.get_card(i).suit << " ";
	}
}


int main() {

	vehicles();

	properties();

	cards();

	return 0;
}