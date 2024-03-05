#include <vector>
#include <numeric>

using namespace std;

class Stack {
private:
	vector<int> elements;

public:
	bool isEmpty() const {
		return elements.empty();
	}

	void push(int value) {
		elements.push_back(value);
	}

	void pop() {
		if (!isEmpty()) {
			elements.pop_back();
		}
	}

	int top() const {
		if (!isEmpty()) {
			return elements.back();
		}
		throw "Stack is empty";
	}

	double average() const {
		if (!isEmpty()) {
			double sum = accumulate(elements.begin(), elements.end(), 0);
			return sum / elements.size();
		}
		return 0; // If the stack is empty, average is set to 0
	}
};
