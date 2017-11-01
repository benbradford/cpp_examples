#pragma once

#include "Dice.h"

class ScoreCard {
public:
	ScoreCard(const Dice& dice) : mDice(dice) {for (auto& i : mCategoryScores) i=-1;}

	void set_score(unsigned int scoreIndex);	
	void print_score();

	bool has_scored(unsigned int scoreIndex) const;
	int total_score() const;

private:

	const char* GetScoreCategoryName(unsigned int scoreIndex);
	int total() const;
	int total_all_with_score(int score) const;
	int highest_duplicate() const;
	bool has_pair() const;
	int small_straight() const;
	int large_straight() const;
	int total_number_scores() const; // 1-6
	int sorted_unique_dice(Die (&dice)[5]) const;

	int mCategoryScores[13];
	int mNumYahtzees;
	const Dice& mDice;
};