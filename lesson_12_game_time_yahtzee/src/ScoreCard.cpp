#include "ScoreCard.h"
#include <iostream>

using namespace std;

bool ScoreCard::is_completed() {

	for (int score : mCategoryScores) {

		if (score == -1) return false;
	}

	return true;
}

void ScoreCard::print_scores(unsigned int (&diceValues)[5]) {

	cout << "1 ones    "; 
	if (mCategoryScores[0] == -1)
		cout << " ? " << total_with_value(diceValues, 1) << " ? " << endl;
	else 
		cout << mCategoryScores[0] << endl;

	cout << "2 twos    "; 
	if (mCategoryScores[1] == -1)
		cout << " ? " << total_with_value(diceValues, 2) << " ? " << endl;
	else 
		cout << mCategoryScores[1] << endl;

	cout << "3 threes  "; 
	if (mCategoryScores[2] == -1)
		cout << " ? " << total_with_value(diceValues, 3) << " ? " << endl;
	else 
		cout << mCategoryScores[2] << endl;

	cout << "4 fours   "; 
	if (mCategoryScores[3] == -1)
		cout << " ? " << total_with_value(diceValues, 4) << " ? " << endl;
	else 
		cout << mCategoryScores[3] << endl;

	cout << "5 fives   "; 
	if (mCategoryScores[4] == -1)
		cout << " ? " << total_with_value(diceValues, 5) << " ? " << endl;
	else 
		cout << mCategoryScores[4] << endl;

	cout << "6 sixes   "; 
	if (mCategoryScores[5] == -1)
		cout << " ? " << total_with_value(diceValues, 6) << " ? " << endl;
	else 
		cout << mCategoryScores[5] << endl;


	cout << "7 triple  ";
	if (mCategoryScores[6] == -1)
		cout << " ? " << "1" << " ? " << endl;
	else 
		cout << "100" << endl;

	cout << "8 quad    ";
	if (mCategoryScores[7] == -1)
		cout << " ? " << "1" << " ? " << endl;
	else 
		cout << "100" << endl;

	cout << "9 full    ";
	if (mCategoryScores[8] == -1)
		if (num_same(diceValues) == 3 && has_pair(diceValues))
			cout << "25" << endl;
		else cout << " ? 0 ?" << endl;
	else 
		cout << mCategoryScores[8] << endl;

	cout << "10 small  ";
	if (mCategoryScores[9] == -1)
		cout << " ? " << "1" << " ? " << endl;
	else 
		cout << "100" << endl;

	cout << "11 large  ";
	if (mCategoryScores[10] == -1)
		cout << " ? " << "1" << " ? " << endl;
	else 
		cout << "100" << endl;

	cout << "12 yahtz  ";
	if (mCategoryScores[11] == -1)
		cout << " ? " << "1" << " ? " << endl;
	else 
		cout << "100" << endl;

	cout << "13 chance ";
	if (mCategoryScores[12] == -1)
		cout << " ? " << "1" << " ? " << endl;
	else 
		cout << "100" << endl;

}

void ScoreCard::set_score(unsigned int scoreIndex, unsigned int (&diceValues)[5]) {

	if (scoreIndex == 1) {

		mCategoryScores[0] = total_with_value(diceValues, 1);

	} else 	if (scoreIndex == 2) {

		mCategoryScores[1] = total_with_value(diceValues, 2);

	} else 	if (scoreIndex == 3) {

		mCategoryScores[2] = total_with_value(diceValues, 3);

	} else 	if (scoreIndex == 4) {

		mCategoryScores[3] = total_with_value(diceValues, 4);

	} else 	if (scoreIndex == 5) {

		mCategoryScores[4] = total_with_value(diceValues, 5);

	} else 	if (scoreIndex == 6) {

		mCategoryScores[5] = total_with_value(diceValues, 6);

	} else if (scoreIndex == 9) {

		if (num_same(diceValues) == 3 && has_pair(diceValues))
			mCategoryScores[8] = 25;
		else
			mCategoryScores[8] = 0;
	} else {

		mCategoryScores[scoreIndex-1] = 100;
	}
	
}

unsigned int ScoreCard::total_with_value(unsigned int (&diceValues)[5], unsigned int value) {

	unsigned int score = 0;
	for (auto v : diceValues) {

		if (v == value)
			score += v;
	}
	return score;
}

unsigned int ScoreCard::num_same(unsigned int (&diceValues)[5]) {

	unsigned int highestSame = 0;

	for (int i = 0; i < 5; ++i) {
		int numSame = 1;

		for (int j = i+1; j < 5; ++j) {

			if (diceValues[i] == diceValues[j]) {
				++numSame;
			}
		}

		if (numSame > highestSame) {
			highestSame = numSame;
		}

	}

	return highestSame;
}

bool ScoreCard::has_pair(unsigned int (&diceValues)[5]) {

	for (int i = 0; i < 5; ++i) {
		bool pair = false;
		bool fail = false;
		for (int j = i+1; j < 5; ++j) {

			if (diceValues[i] == diceValues[j]) {

				if (pair == false) {
					pair = true;
				} else {
					fail = true;
					break;
				}
			}
		}
		if (pair == !fail)
			return true;
	}
	return false;
}

void ScoreCard::score_yahtzee() {

	++mNumYahtzees;
}