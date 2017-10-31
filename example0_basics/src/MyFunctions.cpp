#include "MyFunctions.h" // ensures we can access the file, this will search from the project 'root'

#include <iostream> // to give us access to std::cout and std::endl below.

void PrintHelloWorld() // function definition
{
	std::cout << "Hello World" << std::endl;

	// std::cout refers to the console output
	// the << symbols are streaming operators, more on this later,
	// they are used to signify a stream of strings or ints or characters
	// moving into the console output
	// std::endl means 'end line' and will make the console cursor go to
	// the next line

	// we do not need to return anything from this function since it has
	// a 'void' return type
}


int PrintGoodbye() {

	using namespace std; // allows us to drop the std:: prefix on cout and endl
	// we have defined this local to this function, so only this function
	// uses this namespace.

	// define's an int value to show what we will return.
	int returnValue = 0;

	// in this streaming operation, as well as streaming a string, we can
	// also stream an integer value, as shown below.
	cout << "Goodbye! This function will return: " << returnValue << endl;

	// this function requires an int to be returned, so we return one now
	return returnValue;
}