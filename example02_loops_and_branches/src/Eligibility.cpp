#include "Eligibility.h" 
#include <iostream>

using namespace std;

// note function is not declared in the header
// this means it is only accessible for this file
// this is a good example of restricting what other files can use, we do not want to expose this function
int get_age() {

	cout << "You must be at least 10 to continue!!!" << endl;
	cout << "Please enter your age: ";

	int age;    // note, we cannot use 'age' yet, it is undefined
	cin >> age; // this will read a value from the console and place it in age

	// 'cin' refers to the console input, note the direction of the streaming operator
	// since we are streaming a value from the console and into the age variable
	// if the user doesn't enter a valid int value, then age will be '0'

	return age;
}

// in here we use an if statement to determine what to do based on the inputed age
bool age_check() {

	int age = get_age();

	cout << endl;

	if (age > 120) {

		cout << "You may continue, although I don't know how you're alive" << endl;
	
	} else if (age > 10) {

		cout << "Great, you are old enough" << endl;
	
	} else if (age == 10 ) {

		cout << "OK, you are just about old enough" << endl;
	
	} else if (age < 0) {

		cout << "Don't be funny with me" << endl;
		return false; // return now

	} else if (age == 0) {

		cout << "Either input was bad, or you're somehow aged 0" << endl;
		return false; 

	} else if (age < 4) {

		cout << "How are you even using a computer?!" << endl;
		return false;

	} else {

		cout << "Sorry! Come back in " << 10 - age << " years!" << endl;
		return false; 
	}

	// note the order of condition checking above
	// if we did something like
	/*	if (age > 10) { 
		
			cout << "you are old enough";
		
		} else if (age > 12) {
			cout << "unreachable";
		}
	*/
	// then the second condition could never be entered, since it entered the first
	

	// for negative cases, we always return false
	// therefore if we have made it this far, then the user is old enough
	return true; // age is >= 10
}

// in here we use a switch statement (similar to an if statement)
// we use a while loop to keep looping until we have sensible input
bool purpose_check() {

	cout << "Now you must state your purpose:" << endl;
	cout << "a) to learn how to code" << endl;
	cout << "b) to learn C++" << endl;
	cout << "c) to grow as a person" << endl;
	cout << "d) all of the above" << endl;

	unsigned int attempts_made = 0;

	// this will loop forever
	// inside the brackets is the 'condition' upon which we will execute the next block of code.
	// this while block will execute all the while the number of attempts_made is less than 3
	while (attempts_made < 3) {

		++attempts_made; // we increment the number of attempts made here

		cout << "> ";
		char input;
		cin >> input; // if more than one character is given, then it will read the next one the next time this statement is reached

		// inspect the input and select a case
		// if no 'break' statement is found, then you fall through to the next case below
		// when a 'break' statement is reached, then we break out of the switch statement
		switch(input) {

			case 'a': cout << "I see..."; // no 'break' statement so we fall through to the next case:
			case 'b': cout << "Good, but not enough!" << endl; break;
			case 'c': cout << "There are many ways of achieving this!" << endl; break;
			case 'd': cout << "Then you have come to the right place!" << endl; return true;
			
			// if we cannot match the input to any of the above cases, then we fall into the default case
			default: 
				cout << "Unrecognised selection" << endl << "Please try again";
		}
		
		// this marks the end of the while loop, from here we go back to the while(true) bit 
	} 

	cout << "I see there is no hope for you!" << endl;
	return false;
}