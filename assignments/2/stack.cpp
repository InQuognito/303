#include <iostream>

#include "stack.h"

int main() {
	Stack stack;

	cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

	// Inserting some integer values onto the stack
	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);

	cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

	// Removing an element from the stack
	stack.pop();

	cout << "Top of the stack: " << stack.top() << endl;

	// Finding the average value of the stack elements
	cout << "Average value of the stack elements: " << stack.average() << endl;

	return 0;
}
