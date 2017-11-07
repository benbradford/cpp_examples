#pragma once

#include "Dice.h"

class ScoreCard {
public:
	ScoreCard() {for (auto& i : mCategoryScores) i=-1;}

	void set_score(unsigned int scoreIndex, unsigned int (&diceValues)[5]);	
	void print_scores(unsigned int (&diceValues)[5]);

	bool has_scored(unsigned int scoreIndex);
	int total_score();

	bool is_completed();
	unsigned int num_same(unsigned int (&diceValues)[5]);

	void score_yahtzee();
private:

	//const char* GetScoreCategoryName(unsigned int scoreIndex);
	unsigned int total_with_value(unsigned int (&diceValues)[5], unsigned int value);
	int total(unsigned int (&diceValues)[5]);
	int total_all_with_score(unsigned int score);
	int highest_duplicate(unsigned int (&diceValues)[5]);
	bool has_pair(unsigned int (&diceValues)[5]);
	int small_straight(unsigned int (&diceValues)[5]);
	int large_straight(unsigned int (&diceValues)[5]);
	int total_number_scores(); // 1-6
	//int sorted_unique_dice(Die (&dice)[5]);

	int mCategoryScores[13];
	int mNumYahtzees = 0;
	//Dice& mDice;
};