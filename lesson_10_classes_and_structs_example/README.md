classes and structs

When we want to store information about something, we might want to bundle it together in a struct or a class.

structs and classes are basically the same thing in c++, but we tend to use structs just to store data, and classes to store data and functions to do things with that Data.

classes and structs are just blueprints, you need to do something called instantiation to create an instance or an object.

e.g.

struct Dog {
	
	int mAge;
	string mName;
};


is a struct, which cannot be used until we make an instantiation like so....


Dog dog;
dog.mAge = 5;
dog.mName = "Terry";


In the above class, Dog is a struct and dog is an object of type Dog.


We use classes and structs to group together data which relates to each other. 

More information can be found here: https://www.tutorialspoint.com/cplusplus/cpp_classes_objects.htm



To run this program, from this directory, do the following:

`make`               - starts compiling and generating the executable<br>
`bin/classes`      	 - run the created executable
