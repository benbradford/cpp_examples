#pragma once

class GameRound {
public:

	void start();
private:

	void choose_score();

	int mNumRolls = 0;
};