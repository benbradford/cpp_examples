#pragma once

#include "Dice.h"
#include "ScoreCard.h"

class Game {
public:

	Game();
	
	void start();
private:
	void score();
	void print();

	Dice mDice;
	ScoreCard mScoreCard;
};