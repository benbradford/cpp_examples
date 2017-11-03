#include "Lights.h"

#include <iostream>

using namespace std;

void struct_example();
void class_example();

int main() {

	struct_example();

	class_example();

	return 0;
}

void struct_example() {

	// Light is a struct, it cannot be access directly, you need to create an object of type Light
	Light l;

	// using our new object l, we can access the members of our Light object

	l.on = true;
	l.wattage = 20;
}

unsigned int get_user_input(Lights& lights);

void class_example() {

	Lights lights; // construct a new Lights instance/object called lights

	// taking our ongoing lights example, the main loop now looks a lot neater
	while (lights.are_all_lights_on() == false) {

		lights.print_status();

		unsigned int light_index = get_user_input(lights);

		lights.toggle_light(light_index);

	};

	cout << endl << "All lights are now on! " << endl;
}

unsigned int get_user_input(Lights& lights) {

	unsigned int light_number = 0;
	cout << "Please enter a light switch number: ";
	cin >> light_number;
	cout << endl;

	return light_number - 1;
}