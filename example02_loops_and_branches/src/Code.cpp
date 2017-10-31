#include "Code.h"

#include <iostream>
#include <chrono>

using namespace std;

void pause() {

	// this function will pause for 1 second - ignore the details for now.
	chrono::time_point<std::chrono::system_clock> time = chrono::system_clock::now();
	while ( chrono::system_clock::now() < time + chrono::seconds(1)) {
		
	}
}
void start_coding() {

	int hours_to_code = 0;

	do {

		cout << endl << "How many hours do you wish to code for: ";
		cin >> hours_to_code;

	} while (hours_to_code < 0);

	cout << "starting to code now:" << endl;

	// for loop statement is divided in to three parts. declaration, condition, on_each_iteration
	// in the following, we declare an int, we loop while i is < hours_to_code, at the end of each loop we increment i
	// note '++i' and 'i++'' are interchangable. There is a subtle difference which we will address later
	
	for (int i = 0; i < hours_to_code; ++i) {

		cout << "hours coded for: " << i << endl;
		pause(); // wait for one second

		if (i >= 24) {

			cout << "you have gone insane, time to stop coding" << endl;
			break; // breaks out of the statement
		}
	}
}