#include "HelloWorld.h" // allow us to use anything defined in HellowWorld.h

/* 

	 comments can either be done like this 
	 over several lines
*/

// or like this for a single line

// this is the main function, the compiler will look for this function as the
// starting point of the program
// it returns an int, we return the value 0 to show that the program executed as
// expected, without errors
int main() {

	PrintHelloWorld(); // calls the function declared in HelloWorld.h

	return 0; // main() requires an int to be returned - 0 means all went succesfully
}