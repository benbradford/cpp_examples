#pragma once

#include "Die.h"

class Dice {
public:

	Dice();
	
	void roll();
	void toggle_hold(unsigned int dieIndex);
	bool is_held(unsigned int dieIndex) const;
	void reset_held();
	unsigned int value(unsigned int dieIndex) const;
	void print() const;
	unsigned int num_with_value(unsigned int value) const;
	unsigned int total_with_value(unsigned int value) const;
	unsigned int total() const;
private:
	Die mDice[5];
	unsigned int mTotals[6];
};