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
		
		if (play_round() == false) {
			return;
		}
		
		score();
	}
}

bool Game::play_round() {

	for (int pass_number = 0; pass_number < 2; ++ pass_number) {

		mDice.roll();

		while (true) {

			print(pass_number);

			char input;

			cin >> input;

			if (input == '1') mDice.toggle_hold(0);
			else if (input == '2') mDice.toggle_hold(1);
			else if (input == '3') mDice.toggle_hold(2);
			else if (input == '4') mDice.toggle_hold(3);
			else if (input == '5') mDice.toggle_hold(4);
			else if (input == 's') return true;
			else if (input == 'r') break;
			else if (input == 'q') return false;
		}	
	}

	mDice.roll();
	return true;
}

void Game::score() {

	for (int i = 0; i < 30; ++i) cout << endl;
	mScoreCard.print_scores();
	mDice.print();
	cout << endl << "select score: ";
	unsigned int i;
	cin >> i;
	
	if (i == 0 || i > 13 || mScoreCard.has_scored(i)) {
		score();
		return;
	}
	mScoreCard.set_score(i);
}

void Game::print(int pass_number) const {

	for (int i = 0; i < 30; ++i) cout << endl;
	mScoreCard.print_scores();
		
	mDice.print();
	cout << "score: " << mScoreCard.total_score() << endl;
	cout << "pass " << pass_number+1 << ": ";
			
}