#include "Arrays.h"
#include <iostream>

using namespace std;


void array_example1() {

	cout << "using an array on the stack" << endl;
	cout << "printing 5 even numbers" << endl;

	// DECLARE and POPULATE an array on the stack and give it initial values
	int numbers[] = {0,2,4,6,8};

	// range based for loop is available on stack-based arrays
	for (int n : numbers) {

		cout << n << " ";
	}

	cout << endl;
}

void array_example2() {

	cout << "an array of characters:" << endl;

	// DECLARE an array of 5 characters on the stack
	char characters[5]; // reserve space for 5 chars on the stack - not yet POPULATED

	// although we have reserved space on the stack, the actual values are undefined

	// we can give them values now. We access array elements using []

	// characters[x] refers to the position in memory that 'numbers' points to, + x elements along
		
	characters[0] = 'h';
	characters[1] = 'e';
	characters[2] = 'l';
	characters[3] = 'l';
	characters[4] = 'o';

	/*
		Let's visualise this in memory. We have a block of memory on the stack starting at address 3
		It contains a sequence of chars:
	   _________________
		| |h|e|l|l|o| |
       -----------------
         2 3 4 5 6 7 8 9 .....


         'character' has address 3.
         'character[4]' has address 3 + 4 - therefore it refers to the value in 7: 'o'
	*/

	for (char c : characters) 
		cout << c;

	cout << endl;
}