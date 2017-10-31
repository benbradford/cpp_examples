#include "MyFunctions.h" // allow us to use anything defined in MyFunctions.h

// this is the main function, the compiler will look for this function as the
// starting point of the program
// it returns an int, we return the value 0 to show that the program executed as
// expected, without errors
int main() {

	PrintHelloWorld(); // calls the function declared in MyFunctions.h

	int valueReturned = PrintGoodbye(); // calls a function and stores the return value

	return valueReturned; // main() requires an int to be returned
}