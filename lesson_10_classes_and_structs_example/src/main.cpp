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
	// the constructor is called when the light object is created on the following line:
	Light l;

	// using our new object l, we can access the members of our Light object

	l.on = true;
	l.watts = 20;

	// we can even have an array of Light objects

	Light lights[10];

	lights[4].watts = 123;
}

unsigned int get_user_input();

void class_example() {

	Lights lights; // construct a new Lights instance/object called lights
	lights.set_wattage(0, 50);
	lights.set_wattage(1, 100);
	lights.set_wattage(2, 150);
	lights.set_wattage(3, 200);
	lights.set_wattage(4, 250);

	// taking our ongoing lights example, the main loop now looks a lot neater
	while (lights.are_all_lights_on() == false) {

		lights.print_status();

		unsigned int light_index = get_user_input();

		lights.toggle_light(light_index);

	};

	cout << endl << "All lights are now on! " << endl;
}

unsigned int get_user_input() {

	unsigned int light_number = 0;
	cout << "Please enter a light switch number: ";
	cin >> light_number;
	cout << endl;

	return light_number - 1;
}