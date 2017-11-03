#include <iostream>
using namespace std;


void swap(char& first, char& second) {

	char tmp = first;
	first = second;
	second = tmp;
}

int main() {

	char hello[] = {'o', 'e', 'l', 'l', 'h'};

	swap(hello[0], hello[4]);

	cout << hello << endl;
	
	return 0;
}