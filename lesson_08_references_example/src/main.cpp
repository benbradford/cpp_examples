#include "References.h" 

#include <iostream>
using namespace std;

int main() {

	references();

	int val = 1;

	cout << "value of val is " << val << endl;
	
	increment_ref(val);
	
	cout << "value of val after calling increment_ref is " << val << endl;

	increment_val(val);

	cout << "value of val after calling increment_val is " << val << endl;

	return 0;
}