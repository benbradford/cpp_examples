#include "Lights.h"
#include <iostream>

using namespace std;

// for functions relating to a class, the function name must be prefixed with Lights::
Lights::Lights() {

	// the constructor is called when an instance of the class is created

	// by default, each light is set to off, you can see this in the 
	// definition of the Light struct, where a default value is given to 'on'

	// set some initial values for the lights
	mLights[0].watts = 50;
	mLights[1].watts = 100;
	mLights[2].watts = 150;
	mLights[3].watts = 200;
	mLights[4].watts = 250;

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
