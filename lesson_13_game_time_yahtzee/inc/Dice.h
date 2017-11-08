#pragma once

#include "Die.h"

class Dice {
public:

	Dice();
	
	void roll();
	void toggle_hold(unsigned int dieIndex);
	bool is_held(unsigned int dieIndex);
	void reset_held();
	unsigned int value(unsigned int dieIndex);
	void print();
	unsigned int num_with_value(unsigned int value);
	unsigned int total_with_value(unsigned int value);
	unsigned int total();
private:
	Die mDice[5];
	unsigned int mTotals[6];
};