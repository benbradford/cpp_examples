#pragma once

#include "Die.h"

class Dice {
public:

	void roll();
	void toggle_hold(unsigned int dieIndex);
	bool is_held(unsigned int dieIndex);
	void reset_held();
	int value(unsigned int dieIndex);
	void print();
private:
	Die mDice[5];
};