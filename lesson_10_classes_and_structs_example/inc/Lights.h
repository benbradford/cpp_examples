#pragma once

#include "Light.h"

class Lights {

public: // allow everyone access to these section

	Lights(); // constructor

	int get_number_of_lights();
	bool are_all_lights_on();
	void toggle_light(unsigned int index);
	bool is_light_on(unsigned int index);
	const char* get_light_colour(unsigned int index);

private: // only this class can access this section

	// variables
	Light mLights[5];
};