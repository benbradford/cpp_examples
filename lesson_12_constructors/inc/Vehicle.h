#pragma once

class Vehicle {

public:

	// Use defaults below in private section
	Vehicle() {}

	// constructor taking 3 arguments
	Vehicle(int numberOfWheels, int engineCC, int topSpeed)
	// use the following values for members instead of the defaults given at the bottom
		: mNumberOfWheels(numberOfWheels)
		, mEngineCC(engineCC) 
		, mTopSpeed(topSpeed) {

	}

	// some getter functions
	int number_of_wheels() { return mNumberOfWheels; }
	int engine_cc() { return mEngineCC; }
	int top_speed() { return mTopSpeed; }

private:

	// default values given to each member, these are what are used when default constructing
	int mNumberOfWheels = 2;
	int mEngineCC = 125;
	int mTopSpeed = 60;
};