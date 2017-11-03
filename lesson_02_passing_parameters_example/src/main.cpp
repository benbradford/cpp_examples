#include "Maths.h"

#include <iostream>

using namespace std;

int main() {

	int result = multiply(5, 10); // result is stored in a variable

	cout << "5 times 10 is " << result << endl;

	cout << "The next letter after a is " << next_char('a') << endl; // result of next_char() is not stored but used directly
	
	return 0; 
}