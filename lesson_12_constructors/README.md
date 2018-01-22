constructors

Whenever a class is instantiated, that is, an object of that class is created, the constructor is called.

This is an opportunity to set the member variables to some default values.

If no constructor is defined, then one is created automatically by the compiler and default values are given to all values.

Constructors can take parameters to help decide what initial values to give its members

The constructor must have the same name as the class, and several can be defined, so long as they all take different parameters

`
class MyClass {
public:

	MyClass();
	MyClass(int intValue);
	MyClass(float floatValue);	
};
`

To run this program, from this directory, do the following:

`make`               - starts compiling and generating the executable<br>
`bin/constructors`     - run the created executable
