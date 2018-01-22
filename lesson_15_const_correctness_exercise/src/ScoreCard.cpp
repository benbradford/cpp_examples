#include "ScoreCard.h"
#include <iostream>

using namespace std;

ScoreCard::ScoreCard(Dice& dice) 
	: mDice(dice) {

	for (auto& i : mCategoryScores) i=-1;
}

bool ScoreCard::is_completed() {

	for (int score : mCategoryScores) {

		if (score == -1) return false;
	}

	return true;
}

bool ScoreCard::has_scored(unsigned int scoreCategory) {

	return mCategoryScores[scoreCategory-1] != -1;
}

void ScoreCard::print_scores() {

	cout << "1 ones    "; 
	if (mCategoryScores[0] == -1)
		cout << " ? " << mDice.total_with_value(1) << " ? " << endl;
	else 
		cout << mCategoryScores[0] << endl;

	cout << "2 twos    "; 
	if (mCategoryScores[1] == -1)
		cout << " ? " << mDice.total_with_value(2) << " ? " << endl;
	else 
		cout << mCategoryScores[1] << endl;

	cout << "3 threes  "; 
	if (mCategoryScores[2] == -1)
		cout << " ? " << mDice.total_with_value(3) << " ? " << endl;
	else 
		cout << mCategoryScores[2] << endl;

	cout << "4 fours   "; 
	if (mCategoryScores[3] == -1)
		cout << " ? " << mDice.total_with_value(4) << " ? " << endl;
	else 
		cout << mCategoryScores[3] << endl;

	cout << "5 fives   "; 
	if (mCategoryScores[4] == -1)
		cout << " ? " << mDice.total_with_value(5) << " ? " << endl;
	else 
		cout << mCategoryScores[4] << endl;

	cout << "6 sixes   "; 
	if (mCategoryScores[5] == -1)
		cout << " ? " << mDice.total_with_value(6) << " ? " << endl;
	else 
		cout << mCategoryScores[5] << endl;


	cout << "7 triple  ";
	if (mCategoryScores[6] == -1) {

		unsigned int score = 0;
		if (num_same() >=3)
			score = mDice.total();
		cout << " ? " << score << " ? " << endl;
	} else 
		cout << mCategoryScores[6] << endl;

	cout << "8 quad    ";
	if (mCategoryScores[7] == -1) {

		unsigned int score = 0;
		if (num_same() >=4)
			score = mDice.total();
		cout << " ? " << score << " ? " << endl;
	}
	else 
		cout << mCategoryScores[7] << endl;

	cout << "9 full    ";
	if (mCategoryScores[8] == -1)
		if (full_house()) cout << " ? 25 ? " << endl;
		else cout << " ? 0 ?" << endl;
	else 
		cout << mCategoryScores[8] << endl;

	cout << "10 small  ";
	if (mCategoryScores[9] == -1)
		cout << " ? " << small_straight() << " ? " << endl;
	else 
		cout << mCategoryScores[9] << endl;

	cout << "11 large  ";
	if (mCategoryScores[10] == -1)
		cout << " ? " << large_straight() << " ? " << endl;
	else 
		cout << mCategoryScores[10] << endl;

	cout << "12 yahtz  ";
	if (mCategoryScores[11] == -1){

		unsigned int score = 0;
		if (num_same() ==5)
			score = 50;
		cout << " ? " << score << " ? " << endl;
	}
	else 
		cout << mCategoryScores[11] << endl;

	cout << "13 chance ";
	if (mCategoryScores[12] == -1)
		cout << " ? " << mDice.total() << " ? " << endl;
	else 
		cout << mCategoryScores[12] << endl;

}

void ScoreCard::set_score(unsigned int scoreCategory ) {

	if (num_same() == 5) {

		++mNumYahtzees;
	}

	if (scoreCategory == 1) {

		mCategoryScores[0] = mDice.total_with_value(1);

	} else 	if (scoreCategory == 2) {

		mCategoryScores[1] = mDice.total_with_value(2);

	} else 	if (scoreCategory == 3) {

		mCategoryScores[2] = mDice.total_with_value(3);

	} else 	if (scoreCategory == 4) {

		mCategoryScores[3] = mDice.total_with_value(4);

	} else 	if (scoreCategory == 5) {

		mCategoryScores[4] = mDice.total_with_value(5);

	} else 	if (scoreCategory == 6) {

		mCategoryScores[5] = mDice.total_with_value(6);

	} else if (scoreCategory == 7) {

		if (num_same() >= 3) mCategoryScores[6] = mDice.total();
		else mCategoryScores[6] = 0;

	} else if (scoreCategory == 8) {

		if (num_same() >= 4) mCategoryScores[7] = mDice.total();
		else mCategoryScores[7] = 0;

	} else if (scoreCategory == 9) {

		if (full_house())
			mCategoryScores[8] = 25;
		else
			mCategoryScores[8] = 0;

	} else if (scoreCategory == 10) {

		mCategoryScores[10] = small_straight();

	} else if (scoreCategory == 11) {

		mCategoryScores[10] = large_straight();

	} else if (scoreCategory == 12) {

		if (num_same() == 5) mCategoryScores[11] = 50;
		else mCategoryScores[11] = 0;

	} else if (scoreCategory == 13) {

		mCategoryScores[12] = mDice.total(); 
	} 
	
}

unsigned int ScoreCard::num_same() {

	unsigned int highestSame = 0;

	for (int i = 1; i <= 6; ++i) {
		
		unsigned int numSame = mDice.num_with_value(i);

		if (numSame > highestSame) {
			highestSame = numSame;
		}
	}

	return highestSame;
}

bool ScoreCard::full_house() {

	if (num_same() == 3) {

		for (int i = 1; i <=6; ++i) {

			if (mDice.num_with_value(i) == 2)
				return true;
		}
	}
	return false;
}

unsigned int ScoreCard::large_straight() {
	
	if ((mDice.num_with_value(1) && mDice.num_with_value(2) && mDice.num_with_value(3) && mDice.num_with_value(4) && mDice.num_with_value(5)) 	
		||	(mDice.num_with_value(2) && mDice.num_with_value(3) && mDice.num_with_value(4) && mDice.num_with_value(5) && mDice.num_with_value(6))) {

		return 40;
	}
	return 0;
	
}

unsigned int ScoreCard::small_straight() {
	if ((mDice.num_with_value(1) && mDice.num_with_value(2) && mDice.num_with_value(3) && mDice.num_with_value(4)) 
		|| (mDice.num_with_value(2) && mDice.num_with_value(3) && mDice.num_with_value(4) && mDice.num_with_value(5)) 
		||	(mDice.num_with_value(3) && mDice.num_with_value(4) && mDice.num_with_value(5) && mDice.num_with_value(6))) {

		return 30;
	}
	return 0;
}

unsigned int ScoreCard::total_score() {

	unsigned int total = 0;
	for (int i = 0; i < 13; ++i) {
		if (mCategoryScores[i] != -1)
			total += mCategoryScores[i];
	}
	unsigned int number_score = 0;
	for (int i = 0; i < 6; ++i) {
		if (mCategoryScores[i] != -1)
			number_score+= mCategoryScores[i];
	}

	if (number_score > 64) total += 35;

	if (mNumYahtzees > 1)
		total += (mNumYahtzees-1) * 100;

	return total;

}