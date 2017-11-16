#include "References.h" 

#include <iostream>
using namespace std;

// show's an example of references in action
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


// pass parameter by reference - means that the variable passed in can be changed by this function
void increment_ref(int& value) {

	value++;
}



// pass by value - this function can make changes to value, but it won't affect the value passed in to the function
void increment_val(int value) {

	value++;
}


int main() {

	references();

	int val = 1;

	cout << "value of val is " << val << endl;
	
	increment_ref(val); // value of val will change
	
	cout << "value of val after calling increment_ref is " << val << endl;

	increment_val(val); // value of val will not change

	cout << "value of val after calling increment_val is " << val << "i.e. the same after pass by value" << endl;

	return 0;
}