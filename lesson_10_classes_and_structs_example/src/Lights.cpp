#include "Lights.h"
#include <iostream>

using namespace std;

// for functions relating to a class, the function name must be prefixed with Lights::

void Lights::set_wattage(unsigned int index, int watts) {

	mLights[index] = watts;
}

void Lights::print_status() {

	unsigned int light_count = 1;

	for (Light light : mLights) {

		cout << "Light " << light_count << " is ";
		cout << light.watts << " watts ";
		cout << "and is ";

		if (light.on) cout << "on";
		else cout << "off";

		cout << endl;

		++light_count;
	}
}

bool Lights::are_all_lights_on() {

	for (Light light : mLights) {

		if (light.on == false) return false;
	}

	return true;
}

void Lights::toggle_light(unsigned int index) {

	// protect against user input that is outside of the range 0...4
	if (index >= 5) {

		return;
	}

	mLights[index].on = !mLights[index].on;
}
