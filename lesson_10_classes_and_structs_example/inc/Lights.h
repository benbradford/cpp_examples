#pragma once

#include "Light.h"

class Lights {

// The only difference between structs and classes is that structs allow
// public access by default, whilst classes offer private access by default

public: // allow everyone access to these section

	bool are_all_lights_on();
	void print_status();
	void toggle_light(unsigned int index);
	void set_wattage(unsigned int index, int watts);
	
private: // only this class can access anything declared in the private section

	// variables should always be private in a class, by convention
	Light mLights[5]; // store information on the Light objects here in an array
};