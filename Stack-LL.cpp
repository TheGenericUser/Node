#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
	T value;
	Node* next;

	Node(T value) {
		this->value = value;
		this->next = nullptr;
	}

	~Node() {}
};

template <typename T>
class Stack {
private:
	Node<T>* top; //effectively the head
public:
	Stack() {
		this->top = nullptr;
	}
	void push(T element) {
		Node<T>* temp = new Node<T>(element);
		temp->next = top; //latches to head
		top = temp; //head fix.
	}

	void pop() {
		if (top == nullptr) {
			cout << "Can't pop. No element present in Stack." << "\n";
		}
		else {
			Node<T>* temp = top;
			top = top->next;
			delete temp;
		}
	}

	T peek() {
		if (top == nullptr) {
			return T();
		}
		return top->value;
	}

	inline bool isEmpty() {
		return (top == nullptr);
	}

	void print() {
		Node<T>* temp = top;
		while (temp != nullptr) {
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << "\n";
	}
};

int main(){
	Stack<int> stack;

	stack.print();
	bool breakTrue = true;
	int choice;
	int element; //change
	int topElement; //change
	bool empty, full;
	string* arrayPointer; //change

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
			stack.push(element);
			break;
		case 2:
			stack.pop();
			break;
		case 3:
			topElement = stack.peek();
			if (topElement == 0) { //change depending on type
				cout << "Stack is empty.\n";
			}
			else {
				cout << "Top element is: " << topElement << "\n";
			}
			break;
		case 4:
			empty = stack.isEmpty();
			if (empty) {
				cout << "Stack is empty.\n";
			}
			else {
				cout << "Stack is not empty.\n";
			}
			break;
		case 5:
			stack.print();
			break;
		case 6:
			breakTrue = false;
			break;
		default:
			cout << "Choose from 1-7\n";
			while(!stack.isEmpty()){
				stack.pop();
			}
			break;
		}
	} while (breakTrue);
	return 0;
}