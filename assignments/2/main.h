template <typename Item_Type>
class LinkedList {
private:
	struct Node {
		Item_Type data;
		Node* next;
		Node(const Item_Type& value, Node* nextPtr = nullptr)
			: data(value), next(nextPtr) {}
	};

	Node* head;
	Node* tail;
	size_t num_items;

public:
	LinkedList() : head(nullptr), tail(nullptr), num_items(0) {}

	~LinkedList() {
		while (!empty()) {
			pop_front();
		}
	}

	void push_front(const Item_Type& value) {
		head = new Node(value, head);
		if (num_items == 0) {
			tail = head;
		}
		++num_items;
	}

	void push_back(const Item_Type& value) {
		Node* newNode = new Node(value);
		if (empty()) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		++num_items;
	}

	void pop_front() {
		if (!empty()) {
			Node* temp = head;
			head = head->next;
			delete temp;
			--num_items;
			if (num_items == 0) {
				tail = nullptr;
			}
		}
	}

	void pop_back() {
		if (!empty()) {
			if (num_items == 1) {
				delete head;
				head = tail = nullptr;
			}
			else {
				Node* temp = head;
				while (temp->next != tail) {
					temp = temp->next;
				}
				delete tail;
				temp->next = nullptr;
				tail = temp;
			}
			--num_items;
		}
	}

	Item_Type front() const {
		if (!empty()) {
			return head->data;
		}
		throw out_of_range("List is empty");
	}

	Item_Type back() const {
		if (!empty()) {
			return tail->data;
		}
		throw out_of_range("List is empty");
	}

	bool empty() const {
		return num_items == 0;
	}

	void insert(size_t index, const Item_Type& value) {
		if (index == 0) {
			push_front(value);
		}
		else if (index >= num_items) {
			push_back(value);
		}
		else {
			Node* current = head;
			for (size_t i = 0; i < index - 1; ++i) {
				current = current->next;
			}
			Node* newNode = new Node(value, current->next);
			current->next = newNode;
			++num_items;
		}
	}

	bool remove(size_t index) {
		if (index >= num_items) {
			return false;
		}
		if (index == 0) {
			pop_front();
		}
		else {
			Node* current = head;
			for (size_t i = 0; i < index - 1; ++i) {
				current = current->next;
			}
			Node* temp = current->next;
			current->next = temp->next;
			delete temp;
			--num_items;
		}
		return true;
	}

	size_t find(const Item_Type& value) const {
		Node* current = head;
		size_t index = 0;
		while (current != nullptr) {
			if (current->data == value) {
				return index;
			}
			current = current->next;
			++index;
		}
		return num_items;
	}
};
