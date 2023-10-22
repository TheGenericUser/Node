#include <iostream>
using namespace std;

class Node {
public:
	int value;
	Node* next;

	Node(int value) {
		this->value = value;
		this->next = nullptr;
	}

	~Node() {}
};

class Queue {
private:
	Node* top; //effectively the head
	Node* tail;
public:
	Queue() {
		this->top = nullptr;
		this->tail = nullptr;
	}
	void push(int element) {
		Node* temp = new Node(element);
		Node* start = top;
		if (top == nullptr) {
			top = temp;
			tail = temp;
			return;
		}
		tail->next = temp;
		tail = temp;
	}

	void pop() {
		Node* start = top;
		Node* end = tail;
		if (top == nullptr) {
			cout << "Queue underflow";
			return;
		}
		if (top == tail) {
			delete top;
			top = nullptr;
			tail = nullptr;
			return;
		}
		top = top->next;
		start->next = nullptr;
		delete start;
	}

	int topElement() {
		if (top == nullptr) {
			return -1;
		}
		return (top->value);
	}

	inline bool isEmpty() {
		return (top == nullptr);
	}

	void print() {
		Node* temp = top;
		while (temp != nullptr) {
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << "\n";
	}
};

int main() {
	Queue queue;

	bool breakTrue = true;
	int choice;
	int element; //change
	int topElement; //change
	int* arrayPointer; //change

	do
	{
		cout << R"(
1. Push
2. Pop
3. Top
4. isEmpty
5. Print
6. Exit
)";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Type element to push: ";
			cin >> element;
			queue.push(element);
			break;
		case 2:
			queue.pop();
			break;
		case 3:
			topElement = queue.topElement();
			if (topElement == -1) { //change depending on type
				cout << "Stack is empty.\n";
			}
			else {
				cout << "Top element is: " << topElement << "\n";
			}
			break;
		case 4:
			if (queue.isEmpty()) {
				cout << "Stack is empty.\n";
			}
			else {
				cout << "Stack is not empty.\n";
			}
			break;
		case 5:
			queue.print();
			break;
		case 6:
			breakTrue = false;
			break;
		default:
			cout << "Choose from 1-6\n";
			while (!queue.isEmpty()) {
				queue.pop();
			}
			break;
		}
	} while (breakTrue);
	return 0;
}