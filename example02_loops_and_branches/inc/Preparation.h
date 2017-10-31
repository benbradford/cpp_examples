#pragma once

#include <iostream>

// it is possible to define functionality inside the header instead of the cpp
// this is generally considered bad practice since we are making our headers harder to read
// and we are not hiding our implementation.
// There are other reasons too which we will come on to later

void print_light_state(bool light_1_on, bool light_2_on, bool light_3_on);

void turn_lights_on() {

	// since we are in a header, if we put the following using statement outside of the function,
	// then everything that included Preparation.h would also have full access to the std namespace
	// We probably don't want to do this because namespacing functionality is important.
	// We need to control who we open namespace access to, so here we isolate it to this function
	using namespace std; 

	// in order to proceed, we need to turn all the lights on.

	bool light_1_on = false;
	bool light_2_on = false;
	bool light_3_on = false;

	cout << "Please switch all lights on first" << endl;

	// do...while statements alwayss execute at least once, the condition is at the end of the block
	do {

		print_light_state(light_1_on, light_2_on, light_3_on);

		char light_number = 0;
		cout << "Please press a light switch 1,2 or 3: ";
		cin >> light_number;

		switch(light_number) {

			case '1': light_1_on = !light_1_on; break; // this makes light_1_on hold the opposite value of what it currently holds
			case '2': light_2_on = !light_2_on; break;
			case '3': light_3_on = !light_3_on; break;
			default: cout << " ERROR: unknown selection" << endl;
		}

		// multiple conditions or'ed together
		// all lights must be on to pass
		// if any of the lights aren't on, then we go back to the start of the loop
	} while (light_1_on == false || light_2_on == false || light_3_on == false);

	cout << endl << "All lights are now on! " << endl;
}

void print_light_state(bool light_1_on, bool light_2_on, bool light_3_on) {

	using namespace std;
	cout << "light 1 is ";

	// if the block of an if statement is only one line of code, we do not require brackets{}
	if (light_1_on)
		cout << "on" << endl;
	else
		cout << "off" << endl;

	cout << "light 2 is ";
	if (light_2_on)
		cout << "on" << endl;
	else
		cout << "off" << endl;

	cout << "light 3 is ";
	if (light_3_on)
		cout << "on" << endl;
	else
		cout << "off" << endl;
}