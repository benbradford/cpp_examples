#pragma once

#include "Dice.h"
#include "ScoreCard.h"
#include "GameRound.h"

class Game {
public:

	void start();
private:
	void score(unsigned int (&diceValues)[5]);
	void print();

	Dice mDice;
	ScoreCard mScoreCard;
	GameRound mGameRound;
};