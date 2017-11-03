#include "References.h" 

#include <iostream> 

using namespace std;

void references() {

	cout << "references" << endl;
	int i = 0;

	int& r = i; // r is a reference to i, it refers to exactly the same value

	r = 5; // both r and i now refer to a location on the stack with the value 5

	cout << "the value of i is " << i << " and the value of r is " << r << endl;

	int another_int = 3;

	r = another_int; // make r refer to another variable

	cout << "after assigning again, the value of r is now " << r << endl << endl;

	//int& ref; // ERROR: will not compile; a reference MUST refer to something
}

void increment_ref(int& value) {

	value++;
}

void increment_val(int value) {

	value++;
}
