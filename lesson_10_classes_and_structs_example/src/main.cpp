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
	l.colour = "yellow";
}

void class_example() {

	Lights lights; // construct a new Lights instance/object called lights

	while (lights.are_all_lights_on() == false) {

		for (unsigned int i = 0; i < lights.get_number_of_lights(); ++i) {

			const char* on_string = "off";
			if (lights.is_light_on(i)) 
				on_string = "on";
			
			cout << "Light " << i+1 << " is coloured ";
			cout << lights.get_light_colour(i) << " ";
			cout << "and is " << on_string << endl;
		}

		unsigned int light_number = 0;
		cout << "Please enter a light switch number: ";
		cin >> light_number;
		cout << endl;

		lights.toggle_light(light_number-1);

	};

	cout << endl << "All lights are now on! " << endl;
}