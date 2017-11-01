#include "Code.h"

#include <iostream>
#include <chrono> // contains some useful time functions

using namespace std;

// this function will pause for 1 second
void pause() {

	using namespace chrono; 

	// system_clock::now() returns the current time. 
	// system_clock::now() + seconds(1) returns the time in 1 second's time.
	time_point<system_clock> delay_until = system_clock::now() + seconds(1);
	
	// do nothin whilst we have not yet reached the delay_until time
	// note that this while condition has no {} block, so nothing executes whilst this condition is true
	// we just repeatedly check the condition until it returns false
	while ( chrono::system_clock::now() < delay_until ); 
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
	
	for (int i = 0; i <= hours_to_code; ++i) {

		cout << "hours coded for: " << i << endl;

		// Two conditions are anded together, so both conditions must pass to continue
		// Here we use the modulus operator: https://www.cprogramming.com/tutorial/modulus.html
		if (i > 0 && i % 4 == 0) {

			cout << "coffee break...." << endl;
		}
		pause(); // wait for one second

		if (i >= 24) {

			cout << "you have gone insane!? Time to stop coding, get some sleep!" << endl;
			break; // breaks out of the statement
		}
	}
}