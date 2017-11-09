#pragma once

#include "Dice.h"
#include "ScoreCard.h"

class Game {
public:

	Game();

	void start();
private:
	void score();
	void print(int pass_number) const;
	bool play_round();

	Dice mDice;
	ScoreCard mScoreCard;
};