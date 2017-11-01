#pragma once

#include "Dice.h"
#include "ScoreCard.h"

class Game {
public:

	void start();
private:

	Dice mDice;
	ScoreCard mScoreCard;
};