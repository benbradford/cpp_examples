#include <iostream>

using namespace std; // the entire cpp file now has access to cout, endl and others

// forward declaring functions
void intTypes();
void decimalTypes();
void boolType();
void characterTypes();
void signedAndUnsigned();
void anomalies();


int main() {

	cout << "There is not much output here, best to look at the code to understand the different primitive variable types" << endl;
	
	intTypes();
	decimalTypes();
	boolType();
	characterTypes();
	signedAndUnsigned();
	anomalies();

	return 0;
}

// function definitions

void intTypes() {

	short s = 1;		// the smallest range of int values - usually consumes 2 bytes
	int i = 2;			// the standard range of int values - usually consumes 4 bytes
	long l = 3;			// for when you want to store very big or very store values - usually consumes 8 bytes
	long long ll = 4;	// for when you want to store extremely big or small values - usually consumes 8 bytes 

}

void decimalTypes() {

	float f = 0.0f;		// for standard decimal values - note the f on the end to mean float - usually consumes 4 bytes
	double d = 1.0;		// for large decimal values - usually consumes 4 bytes

}

void boolType() {

	bool b = true;		// bool values can be either true
	b = false;			// or false

}

void characterTypes() {

	char c = 'a';		// a single character, use '' for values - usually consumes 1 byte
}

void signedAndUnsigned() {

	// signed values can be positive or negative
	// unsigned values can only be positive
	// each integer (and char) variable type has a default when the signage is not specified

	// signed values use their most signficant bit to indicate if it is positive or negative
	// this means, the left most 0 or 1 in their binary representation is used to indicate signage
	// if this value is 0 then the number is positive
	// if this value is 1 then the number is negative
	// more information here: https://en.wikipedia.org/wiki/Two%27s_complement

	// note that since unsigned numbers do not require a bit to indicate signage,
	// it means that these numbers can therefore be double the size, since the bit is not wasted on signage

	// signed can be positive or negative
	signed char c = 'a';
	signed short s = -1;
	signed int i = -2;
	signed long l = -3;
	signed long long ll = -4;

	// unsigned can only be positive
	unsigned char uc = 'b';
	unsigned short us = 1;
	unsigned int ui = 2;
	unsigned long ul = 3;
	unsigned long long ull = 4;
}

void anomalies() {

	// here we show some things to look out for

	int i; // i is DECLARED but not DEFINED. it has no value

	// i++; // if we tried to do this, our behaviour would be UNDEFINED
	// for more information on undefined behaviour see https://en.wikipedia.org/wiki/Undefined_behavior

	unsigned short us = -1; // but unsigned values must be positive!

	// this will compile fine, but it will have a binary value of 1111111111111111
	// this is the highest possible value a short can be.
	cout << "'us' " << "is an unsigned variable, but was given a positive value!";
	cout << "luckily c++ wraps around, and therefore its value is " << us << endl;

}