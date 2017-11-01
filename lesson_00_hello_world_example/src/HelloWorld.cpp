#include "HelloWorld.h" // ensures we can access the file, this will search from the project 'root'

#include <iostream> // to give us access to std::cout and std::endl below.

using namespace std; // functions in iostream are within a namespace, 
// that means we can either use the namespace prefix each time we use something from there
//    std::cout 
// or call using namespace;
//    cout

void PrintHelloWorld() // function definition
{
	cout << "Hello World" << endl;

	// std::cout refers to the console output
	// the << symbols are streaming operators, more on this later,
	// they are used to signify a stream of strings or ints or characters
	// moving into the console output
	// std::endl means 'end line' and will make the console cursor go to
	// the next line

	// we do not need to return anything from this function since it has
	// a 'void' return type
}

