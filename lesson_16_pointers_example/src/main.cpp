#include <iostream>
using namespace std;



class Test {
public:

	struct T {
		T() {cout << "ctor" << endl;}
		~T() {cout << "dtor" << endl;}

		T(const T&) {cout << "copy ctor" << endl;}
		T(T&&) {cout << "move ctor" << endl;}
		T& operator=(T&&) {cout << "op=" << endl; return *this;}
		T& operator=(const T&) { cout << "move op =" << endl;return *this; }
	};

	void Add(T&& i) {
		Foo(i);
	}

	void Add(const T& i) {
		Foo(i);
	}

	void Convert(T&& t) {

		t = T{};
	}

	void Convert(T& t) {

		t = T{};
	}

	void Blah(T&& t) {

		Convert(t);
	}

private:

	T Foo(const T& t) {

		return t;
	}
};


int main() {
	Test t1;
	Test::T m;
	//t1.Add(std::move(m));
	t1.Blah(std::move(m));
	//t1.Convert(m);
	//Test::T t;
	//t1.Add(t);

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

	return 0;
}