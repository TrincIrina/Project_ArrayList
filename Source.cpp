#include<iostream>
#include"ArrayList.h"
using namespace std;

double ArrayList::k = 1.6;

void main() {
	srand(time(NULL));

	ArrayList mass(15);
	for (int i = 0; i < 10; i++) {
		int num = rand() % 50;
		mass.add_back(num);
	}
	cout << mass.to_string() << endl << endl;
	mass.delete_back();
	mass.delete_index(3);
	mass.delete_front();
	mass.set_elem(4, -55);
	cout << mass.to_string() << endl << endl;
	cout << "Capacity: " << mass.get_capacity() << endl;
	cout << "Size: " << mass.get_size() << endl << endl;
	mass.shrink();
	cout << "Size: " << mass.get_size() << endl << endl;

	ArrayList bar(10, 33);
	cout << bar.to_string() << endl << endl;
	
	bar.add_front(-55);
	bar.add_index(4, -55);
	bar.add_back(-55);
	cout << bar.to_string() << endl << endl;
	cout << "Capacity: " << bar.get_capacity() << endl;
	cout << "Size: " << bar.get_size() << endl;
	cout << "5 element: " << bar.get_elem(4) << endl << endl;
	
	
}