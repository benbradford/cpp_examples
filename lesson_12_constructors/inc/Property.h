#pragma once

class Property {

public:

	Property() 
		: mNumberOfFloors(1)
		, mNumberOfBedrooms(2) {

	}

	Property(int numberOfFloors, int numberOfBedrooms) 
		: mNumberOfFloors(numberOfFloors)
		, mNumberOfBedrooms(numberOfBedrooms) {

	}

	int number_of_floors() { return mNumberOfFloors; }
	int number_of_bedrooms() { return mNumberOfBedrooms; }

private:

	int mNumberOfFloors;
	int mNumberOfBedrooms;
};