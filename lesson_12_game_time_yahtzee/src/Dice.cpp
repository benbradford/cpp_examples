#include "Dice.h"
#include <cstdlib> // for rand()
#include <iostream>
using namespace std;

void Dice::roll() {

	for (Die& d : mDice)
		if (d.held == false)
			d.value = (rand() % 6) + 1;
}

void Dice::toggle_hold(unsigned int dieIndex) {

	mDice[dieIndex].held = !mDice[dieIndex].held;
}

bool Dice::is_held(unsigned int dieIndex) {

	return mDice[dieIndex].held;
}

void Dice::reset_held() {

	for (Die& d : mDice)
		d.held = false;
}

int Dice::value(unsigned int dieIndex) {

	return mDice[dieIndex].value;
}

void Dice::print() {

	for (Die d : mDice) {

		cout << d.value << " ";
	}
	cout << endl;
	for (Die d : mDice) {

		if (d.held)
			cout << "H" << " ";
		else
			cout << "  ";
	}
	cout << endl;
}
