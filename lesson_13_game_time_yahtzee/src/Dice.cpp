#include "Dice.h"
#include <cstdlib> // for rand()
#include <iostream>
using namespace std;

Dice::Dice() {

	for (int i = 0; i < 6; ++i)
		mTotals[i] = 0;
}

void Dice::roll() {

	for (int i = 0; i < 6; ++i)
		mTotals[i] = 0;

	for (Die& d : mDice) {
		if (d.held == false) {
			d.value = (rand() % 6) + 1;
		}

		mTotals[d.value-1] = mTotals[d.value-1]+1;
	}

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

unsigned int Dice::value(unsigned int dieIndex) {

	return mDice[dieIndex].value;
}

unsigned int Dice::num_with_value(unsigned int value) {

	return mTotals[value-1];
}

unsigned int Dice::total_with_value(unsigned int value) {

	return mTotals[value-1] * value;
}

unsigned int Dice::total() {

	unsigned int total = 0;
	for (Die& d : mDice) {

		total += d.value;
	}
	return total;
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
