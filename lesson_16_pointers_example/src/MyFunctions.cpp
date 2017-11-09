#include "MyFunctions.h" // ensures we can access the file, this will search from the project 'root'

#include <iostream> // to give us access to std::cout and std::endl below.

using namespace std;

void stack_scope() {

	char c = 'c';

	// c now lives on the top-most memory stack
	// when we get to the closing } below, the stack is 'popped' and c no longer exists

	if (c == 'c') {

		// once we enter here, we have an entirely new scope

		bool b = true;

		// b now exists on the top most stack, within this top scope

		c = 'b'; // we can still access c however, since it is in the 'outer scope'

		// the scoping rules say to look for variables in the current scope first
		// then if it cannot find a variable of that name, progressively look in the outer scopes		

		int c = 5; // define a new variable called c in the inner scope

		// we can now no longer access that char c above, because our scope rules say we
		// look in the immediate scope first. Therefore, c refers to the new int c above

		c = 10;
	} // when we exit this if statement, the scope if ends, therefore b is deleted, as is the int version of c


	c = 'a'; // we can still access our char c above

	// b = false; ERROR b has gone out of scope

} // stack is popped and char c is now out of scope

void pointers() {

	cout << "pointers" << endl;
	int i = 0;

	int* p; // p is a pointer to an area of memory containing an int. Note that this hasn't been assigned a location yet

	p = &i; // & here means 'address of', so p now points to the area of memory where i is stored.

	*p = 3; // in order to access the value which p points to, the * operator is required

	cout << "the value of i is " << i << " and the value that p points to is " << *p << endl;


	/*
		Imagine we have a block of memory storing our variables
		We can see the values held inside the memory
		Below we can see the memory address location
		Below that we can see the name of the variable that holds the value there


		__________________
		| 3 |   |   | 5 |
        ------------------
		  5   6   7   8
		  i           p


		  i contains the int value of 3
		  p contains the memory address value of 5 (which is the location of i's 3)
		  Therefore, in this case, the value of p is 5 and the value which p points to is 3
	*/

	// note that if we didn't use * before the p, then we would adjust the memory location that p
	// points to, rather than the value that it points to!
	// if we cout the value of p, we would get a memory address location instead:

	cout << "p points to a memory address at " << p << endl;

	// unlike references, p can point to 'nothing'. we call this a null pointer
	p = nullptr;

	// we can now not use p for anything or we will get a runtime crash called a 'segmentation fault'
	
	// *p = 10; // WARNING, do not do this!

	// we can check if p holds a value or not like this:

	if (p) cout << "p holds a value";
	else   cout << "p now holds no value" << endl << endl;
	
}

void memory_allocation() {

	// this is a tricky section, I recommend looking at http://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/

	float* f; // f is a pointer with an undefined value

	// In order for f to hold a value, we need to allocate some memory to store it.
	// We do this via the 'new' keyword, which will reserve some space in heap memory.
	// Later, we will see how we can never use new, because it can be troublesome....
	f = new float; // f now points to an area of memory reserved to hold a float, but the float is not yet defined

	// we can now use f like a normal pointer
	*f = 1.0f; // the area of memory that f points to, now contains a float with value 1.0

	cout << "f is a float pointer with memory address " << f;
	cout << ". In that area of memory is a float with value " << *f << endl << endl;

	// Once we have finished with f, we need to delete the area on the heap where we allocated space for it
	// If we do not delete it the space will stay reserved and nothing else could ever use it.
	// However at the end of this function, since f is held on the stack we could no longer access it
	// the memory location on the heap that we reserved memory space for. This is called a memory leak
	delete f;
}

void heap_allocated_array(int amount) {

	cout << endl << "printing 10 times table" << endl;

	// since we don't know at compile time, how big to make the array, we need to use some trickery

	// an array is really just a pointer to a sequence
	// the following declaration tells us that we are going to point to somewhere in memory
	// which will contain a sequence of int values. Although we haven't defined this yet
	int* numbers;

	// the following will create some memory on the heap where we can store 'amount' integers
	// 'numbers' will point to the memory location of the start of the sequence
	// the numbers will all sit next to each other in memory
	numbers = new int[amount];

	// we have now 'reserved' some space in memory to store 10 integers
	// however, we have not put any actualy values into memory yet, so we have 'undefined' values there

	// we can now loop through this array and populate it with some values
	// in c++ arrays start at index 0
	for (int i=0; i < amount; ++i) {

		numbers[i] = i * 10;
	}

	// now we can loop through this array and print out the values
	// note that you cannot use range-based for loops over pointer types, since the compiler
	// does not know where the end of the array is, it just knows that 'numbers' is a pointer
	for (int i=0; i < amount; ++i) {

		cout << numbers[i] << endl;
	}

	// whenever we 'new' an array, we have to delete it again
	// the [] part tells the compiler that this is an array we are deleting.
	delete [] numbers;
}
