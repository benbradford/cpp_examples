#include "Lights.h"
#include <iostream>

using namespace std;
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
	mLights[0].wattage = 50;
	mLights[1].wattage = 100;
	mLights[2].wattage = 150;
	mLights[3].wattage = 200;
	mLights[4].wattage = 250;

}

void Lights::print_status() {

	unsigned int light_count = 1;
	
	for (Light light : mLights) {

		cout << "Light " << light_count << " is ";
		cout << light.wattage << " watts ";
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
