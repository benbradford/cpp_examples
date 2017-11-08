#pragma once

#include "Dice.h"

class ScoreCard {
public:
	ScoreCard(Dice& dice);

	void set_score(unsigned int scoreCategory);	
	void print_scores();

	bool has_scored(unsigned int scoreCategory);
	unsigned int total_score();

	bool is_completed();
	unsigned int num_same();

	void score_yahtzee();
private:

	unsigned int total_all_with_score(unsigned int score);
	unsigned int small_straight();
	unsigned int large_straight();
	unsigned int total_number_scores(); // 1-6
	bool full_house();
	
	Dice& mDice;
	int mCategoryScores[13];
	unsigned int mNumYahtzees = 0;
	
};