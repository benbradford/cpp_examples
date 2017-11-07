#include "Game.h"

#include <cstdlib> // for rand()
#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

long now() {
	return (duration_cast<milliseconds>(time_point_cast<milliseconds>(system_clock::now()).time_since_epoch())).count();
}


void Game::start() {

	int round;
	srand(now());
	
	
	while(mScoreCard.is_completed() == false) {

		mDice.reset_held();
		unsigned int values[5];
		bool scored = false;

		for (int round = 0; round < 2; ++ round) {
			mDice.roll();

			
			for (int  i = 0; i < 5; ++i) {

				values[i] = mDice.value(i);
			}

			scored = false;
			while (scored == false) {

				for (int i = 0; i < 30; ++i) cout << endl;
				mScoreCard.print_scores(values);
			
				mDice.print();

				cout << "round " << round+1 << ": ";
				char input;

				cin >> input;

				if (input == 'q') {

					return;
				}

				if (input == '1') {
					mDice.toggle_hold(0);
				} else if (input == '2') {
					mDice.toggle_hold(1);
				} else if (input == '3') {
					mDice.toggle_hold(2);
				} else if (input == '4') {
					mDice.toggle_hold(3);
				} else if (input == '5') {
					mDice.toggle_hold(4);
				} else if (input == 's') {
					score(values);
					break;
				} else if (input == 'r') {
					break;
				}
			}	
		}
		if (!scored) {

			score(values);
		}
		
	}

}

void Game::score(unsigned int (&diceValues)[5]) {

	cout << endl << "select score: ";
	unsigned int i;
	cin >> i;
	if (i > 13) {
		score(diceValues);
		return;
	}
	mScoreCard.set_score(i, diceValues);
}

void Game::print() {

	mDice.print();
}