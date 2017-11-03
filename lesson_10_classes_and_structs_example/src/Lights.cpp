#include "Lights.h"

// for functions relating to a class, the function name must be prefixed with Lights::

Lights::Lights() {

	// the constructor is called when an instance of the class is created

	// set all lights to off
	// we can do this with a range-based for loop, but we must take a reference to each Light
	// otherwise our changes will have no effect on the original array of mLights
	for (Light& l : mLights) {

		l.on = false;
	}

	// set some initial values for the lights
	mLights[0].colour = "Yellow";
	mLights[1].colour = "White";
	mLights[2].colour = "Blue";
	mLights[3].colour = "Red";
	mLights[4].colour = "Green";

}

int Lights::get_number_of_lights() {

	return 5;
}

bool Lights::are_all_lights_on() {

	for (Light& l : mLights) {

		if (l.on == false) return false;
	}

	return true;
}

void Lights::toggle_light(unsigned int index) {

	if (index >= lights.get_number_of_lights()) {

		return;
	}

	mLights[index].on = !mLights[index].on;
}

bool Lights::is_light_on(unsigned int index) {

	return mLights[index].on;
}

const char* Lights::get_light_colour(unsigned int index) {

	return mLights[index].colour;
}