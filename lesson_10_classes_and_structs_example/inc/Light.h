#pragma once

// declare a struct which contains 2 variables
struct Light {

	// by default, all members are publically available in a struct
	// this means, anyone can access the members (via an object of this type)
	bool on;
	int wattage;
};

// a struct is just a blueprint. in order to access the members, you need to
// create an object of type Light.