#pragma once

#include "Die.h"

class Dice {
public:

	void roll();
	void toggle_hold(unsigned int dieIndex);
	bool is_held(unsigned int dieIndex) const;
	void reset_held();

	//auto dice() const -> const Die(&)[5] { return mDice; }
	const Die (&dice() const)[5];
private:
	Die mDice[5];
};