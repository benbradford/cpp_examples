#pragma once

#include "Dice.h"

class ScoreCard {
public:
	ScoreCard(const Dice& dice);

	void set_score(unsigned int scoreCategory);	
	void print_scores() const;

	bool has_scored(unsigned int scoreCategory) const;
	unsigned int total_score() const;

	bool is_completed() const;
	unsigned int num_same() const;

private:

	unsigned int small_straight() const;
	unsigned int large_straight() const;
	unsigned int total_number_scores() const; // 1-6
	bool full_house() const;
	
	const Dice& mDice;
	int mCategoryScores[13];
	unsigned int mNumYahtzees = 0;
	
};