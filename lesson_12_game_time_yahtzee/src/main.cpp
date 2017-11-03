// WIP needs refactoring
#include <cstdlib> // for rand()
#include <chrono>
#include <iostream>
#include <array>
#include <string>
#include <functional>
#include <vector>

using namespace std;
using namespace chrono;

namespace ttest {

	#include "ScoreCard.h"
}
long now() {
	return (duration_cast<milliseconds>(time_point_cast<milliseconds>(system_clock::now()).time_since_epoch())).count();
}

void clear() {

	for (int i =0; i < 50; ++i) {
		cout << endl;
	}
}

class Dice {

public:

	Dice();

	void roll();
	int value() const;
	void toggle_hold();
	bool held() const { return mHeld; }
	void reset_held() { mHeld = false; }
private:

	int mValue;
	bool mHeld = false;
};

Dice::Dice() {

	roll();
}

void Dice::roll() {

	if (mHeld == false)
		mValue = (rand() % 6) + 1;
}

int Dice::value() const {

	return mValue;
}

void Dice::toggle_hold() {

	mHeld = !mHeld;
}

Dice dice[5];
int round = 1;
int scorecard[13];
int num_yahtzee = 0;
bool bonus = false;

static const std::array<std::string, 13> score_strings = 
{
	"1  ones     ",
	"2  twos     ",
	"3  threes   ",
	"4  fours    ",
	"5  fives    ",
	"6  sixes    ",
	"7  tripl    ",
	"8  quad     ",
	"9  full     ",
	"10 s str    ",
	"11 l str    ",
	"12 yahtzee  ",
	"13 chance   "
};

int count(int num) {

	int tot = 0;
	for (const auto& d : dice) 
		tot += d.value() == num ? num : 0;
	return tot;
}

int total() {

	int tot = 0;
	for (const auto& d : dice) 
		tot += d.value();
	return tot;
}

int num_same() {

	int highestSame = 0;

	for (int i = 0; i < 5; ++i) {
		int numSame = 1;

		for (int j = i+1; j < 5; ++j) {

			if (dice[i].value() == dice[j].value()) {
				++numSame;
			}
		}

		if (numSame > highestSame) {
			highestSame = numSame;
		}

	}

	return highestSame;
}

bool has_pair() {

	for (int i = 0; i < 5; ++i) {
		bool pair = false;
		bool fail = false;
		for (int j = i+1; j < 5; ++j) {

			if (dice[i].value() == dice[j].value()) {

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

int trips() {

	if (num_same() >= 3)
		return total();
	return 0;
}

int quads() {

	if (num_same() >= 4)
		return total();
	return 0;
}

int full() {

	if (num_same() == 3 && has_pair()) 
		return 25;
	return 0;
}

std::vector<int> sorted() {

	std::vector<int> vals;
	for (const Dice& d : dice) {

		vals.push_back(d.value());
	}

	std::sort(vals.begin(), vals.end());
	return vals;
}

void remove_duplicates(std::vector<int> & values) {

	for (int i = i; i < values.size(); ++i) {

		for (int j = i+1; j < values.size(); ++j) {

			if (values[i] == values[j]) {

				cout << "found duplicate of " << values[i] << endl;
				values.erase(values.begin() + i);
				remove_duplicates(values);
				return;
			}
		}
	}
}

int small() {

	auto vals = sorted();
	remove_duplicates(vals);
	
	for (int i = 0; i < 2; ++i) {

		bool ok = true;
		int numInRow = 0;

		for (int j = i+1; j < vals.size(); ++j) {

			if (vals[j] != vals[j-1]+1) {
				ok = false;
				break;
			}
			numInRow++;
			if (numInRow == 4) break;
		}

		if (ok) return 30;
	}
	return 0;
}

int large() {

	auto vals = sorted();
		
	remove_duplicates(vals);

	if (vals.size() < 5) {

		return 0;
	}
	
	for (int i = 1; i < 5; ++i) {
		if (vals[i] != vals[i-1]+1) {
			return 0;		
		}
	}
	return 40;
}

int yahtzee() {

	if (num_same() == 5) {
		
		return 50;
	}
	return 0;
}

int chance() {

	return total();
}

int tot_numbers() {

	int tot=  0;

	for (int i = 0; i < 6; ++i) {

		tot += scorecard[i] == -1 ? 0 : scorecard[i];
	}
	return tot;
}

static const std::array<std::function<int()>, 13> score_funcs = 
{
	[]() { return count(1); },
	[]() { return count(2); },
	[]() { return count(3); },
	[]() { return count(4); },
	[]() { return count(5); },
	[]() { return count(6); },
	[]() { return trips(); },
	[]() { return quads(); },
	[]() { return full(); },
	[]() { return small(); },
	[]() { return large(); },
	[]() { return yahtzee(); },
	[]() { return chance(); }
};

bool scorecard_full() {

	for (int i = 0; i < 13; ++i) {

		if (scorecard[i] == -1)
			return false;
	}
	return true;
}

int print_score(int index) {

	cout << score_strings[index]; 

	if (scorecard[index] != -1) {
		
		cout << " = " << scorecard[index] << endl;
		return scorecard[index];
	}
	cout << endl;
	return 0;
}

void print_scorecard() {

	int total = 0;
	int bonus = 0;
	
	for (int i = 0; i < 13; ++i) {

		total += print_score(i);
	}

	if (tot_numbers() > 64) {

		bonus += 35;
	}

	bonus += num_yahtzee ? ((num_yahtzee - 1) * 100) : 0;

	if (bonus) {

		cout << "Bonus: " << bonus << endl;
	}

	total += bonus;

	cout << "Total Score: " << total;
	cout << endl << endl;
}

void score() {

	while (true) {
	
		cout << "Select score: ";
		int index;
		cin >> index;
		cout << endl;

		if (index < 1 || index > 13 || scorecard[index-1] != -1)
			continue;

		scorecard[index-1] = score_funcs[index-1]();

		break;
	}
}

void print() {

	clear();

	print_scorecard();	

	cout << "Round: " << round << endl << endl;
	for (auto& d : dice) {

		cout << d.value() << " ";
	}

	cout << endl;
	for (auto& d : dice) {

		const char* text = "H ";
		if (d.held() == false) text = "  ";
		cout << text;
	}
	cout << endl;
}

int main() {

	srand(now());
	char input;

	for (auto& s : scorecard) s = -1;

	while(scorecard_full() == false) {

		for (auto& d : dice){ d.reset_held(); d.roll(); };

		bool scored = false;

		for (round = 1; round <3 && scored == false; ++round) {

			if (num_same() == 5) {

				++num_yahtzee;
				break;
			}
			cout << endl;

			do {
				print();
				cout << "round " << round << ": ";
				cin >> input;

				if (input == 'q') {
					return 0;
				}

				if (input >= '1' || input <= '5') {

					int indexToHold = (int)(input - '1');
					dice[indexToHold].toggle_hold();
				}

				if (input == 's') {

					score();
					scored = true;
					break;
				}
			}
			while (input != 'r');	
			
			for (auto& d : dice) {

				d.roll();
			}

			print();
		}

		if (scored == false) {

			score();
		}
	}

	return 0;
}