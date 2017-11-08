#include "Game.h"

#include <cstdlib> // for rand()
#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

long now() {
	return (duration_cast<milliseconds>(time_point_cast<milliseconds>(system_clock::now()).time_since_epoch())).count();
}

Game::Game()
	: mScoreCard(mDice) {

}

void Game::start() {

	srand(now());
	
	while(mScoreCard.is_completed() == false) {

		mDice.reset_held();
		bool scored = false;

		for (int round = 0; round < 2; ++ round) {


			mDice.roll();

			scored = false;
			while (scored == false) {

				for (int i = 0; i < 30; ++i) cout << endl;
				mScoreCard.print_scores();
			
				mDice.print();

				cout << "round " << round+1 << ": ";
				char input;

				cin >> input;

				if (input == 'q') {

					return;
				}

				if (input == '1') mDice.toggle_hold(0);
				else if (input == '2') mDice.toggle_hold(1);
				else if (input == '3') mDice.toggle_hold(2);
				else if (input == '4') mDice.toggle_hold(3);
				else if (input == '5') mDice.toggle_hold(4);
				else if (input == 's') {
					score();
					scored = true;
					break;
				} else if (input == 'r') {
					break;
				}
			}	
		}
		if (!scored) {

			score();
		}
		
	}

}

void Game::score() {

	cout << endl << "select score: ";
	unsigned int i;
	cin >> i;
	
	if (i == 0 || i > 13 || mScoreCard.has_scored(i)) {
		score();
		return;
	}
	mScoreCard.set_score(i);
}

void Game::print() {

	mDice.print();
}