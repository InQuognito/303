#include <iostream>

#include "main.h"

using namespace std;

int main() {
	LinkedList<int> list;
	list.push_back(10);
	list.push_back(20);
	list.push_back(30);
	list.push_front(5);

	cout << "Front: " << list.front() << endl;
	cout << "Back: " << list.back() << endl;

	list.insert(2, 15);
	cout << "Element at index 2: " << list.find(15) << endl;

	list.remove(3);
	cout << "Element at index 3: " << list.find(30) << endl;

	return 0;
}
