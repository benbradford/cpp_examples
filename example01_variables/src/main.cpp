#include <iostream>
#include <limits> // to give us access to std::numeric_limits, used below

using namespace std; // the entire cpp file now has access to cout, endl and others

// forward declaring functions
void intTypes();
void decimalTypes();
void boolType();
void characterTypes();
void signedAndUnsigned();
void anomalies();

// a function to output information about variable types
// this is a templated function, which means we can pass type information in
// more information on templates later, this is a more advance topic
template <typename T>
void print_information(const char* name, const T& value) {

	cout << "#" << name << endl;
	cout << "We have a " << name << " with value " << value << endl;
	cout << "On this machine, " << name << "s are made up of " << sizeof(T) << " bytes";
	cout << " or " << sizeof(T) * 8 << " bits.";
	cout << " It has a min value of " << numeric_limits<T>::min();
	cout << " and a max value of " << numeric_limits<T>::max() << endl;
	cout << endl;

}

int main() {

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

	short s = 1;		// the smallest range of int values
	int i = 2;			// the standard range of int values
	long l = 3;			// for when you want to store very big or very store values
	long long ll = 4;	// for when you want to store extremely big or small values

	// output some information on these variables
	cout << "*** Integers ***" << endl;
	print_information<short>("short", s);
	print_information<int>("int", i);
	print_information<long>("long", l);
	print_information<long long>("long long", ll);
	cout << "****************" << endl;
}

void decimalTypes() {

	float f = 0.0f;		// for standard decimal values - note the f on the end to mean float
	double d = 1.0;		// for large decimal values

	cout << endl << "*** Decimals ***" << endl;
	print_information<float>("float", f);
	print_information<double>("double", d);
	cout << "****************" << endl;

}

void boolType() {

	bool b = true;		// bool values can be either true
	b = false;			// or false

	cout << endl << "*** Boolean ***" << endl;
	print_information<bool>("bool", b);
	cout << "***************" << endl;
}

void characterTypes() {

	char c = 'a';		// a single character, use '' for values
	const char* s = "hello world"; // this is a pointer to a string of characters

	// const char* is a strange variable declaration
	// it means 'a pointer in memory to the start of a sequence of characters'
	// This declaration will actually add a \0 character to the end of the sequence
	// This is used to tell us when the sequence of characters stop

	cout << endl << "*** Characters ***" << endl;
	print_information<char>("char", c);
	// we cannot print information on const char*
	cout << "****************" << endl;
}

void signedAndUnsigned() {

	// signed values can be positive or negative
	// unsigned values can only be positive
	// each integer (and char) variable type has a default when the signage is not specified

	// signed values use their most signficant bit to indicate if it is positive or negative
	// this means, the left most 0 or 1 in the binary representation is used to indicate signage
	// if this value is 0 then the number is positive
	// if this value is 1 then the number is negative
	// more information here: https://en.wikipedia.org/wiki/Two%27s_complement

	// note that since unsigned numbers do not require a bit to indicate signage,
	// it means that these numbers can therefore be large, since the bit is not wasted

	signed char c = 'a';
	signed short s = 0;
	signed int i = 1;
	signed long l = 2;
	signed long long ll = 3;

	unsigned char uc = 'b';
	unsigned short us = 4;
	unsigned int ui = 5;
	unsigned long ul = 6;
	unsigned long long ull = 7;

	cout << "*** Signage ***" << endl;
	cout << "== Signed" << endl;
	print_information<signed char>("signed char", c);
	print_information<signed short>("signed short", s);
	print_information<signed int>("signed int", i);
	print_information<signed long>("signed long", l);
	print_information<signed long long>("signed long long", ll);
	cout << "**************" << endl;
	cout << "== Unsigned" << endl;
	print_information<unsigned char>("unsigned char", uc);
	print_information<unsigned short>("unsigned short", us);
	print_information<unsigned int>("unsigned int", ui);
	print_information<unsigned long>("unsigned long", ul);
	print_information<unsigned long long>("unsigned long long", ull);
	cout << "**************" << endl;
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