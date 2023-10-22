//arrays

#include <iostream>
using namespace std;

template <typename T>
class Stack{
public:
	T* array;
	int top;
	int size;

	Stack(int size) {
		this->size = size;
		this->array = new T[size]; //this will alloacte memory, the whole chunk, eg: 4(int)*6(size)=24 bytes. (char is 8 bits)
		this->top = -1;
	}

	void push(T &element) {
		if ((this->top+1) < size) {
			this->top++;
			array[this->top] = element;
		}
		else {
			cout << "Can't push. Stack size exceeded." << "\n";
		}
	}

	void pop() {
		if (this->top > -1) {
			this->top--; //will be overwritten. can't use delete as i wont be able to use the space afterwards.
		}
		else {
			cout << "Can't pop. No element present in Stack." << "\n";
		}
	}

	T peek() {
		if (this->top > -1) {
			return array[this->top];
		}
		return T();
	}

	inline bool isEmpty() {
		return (this->top == -1);
	}

	inline bool isFull() {
		return ((this->top + 1) == size);
	}

	T* print() {

		return array;
	}
};

int main() {
	bool breakTrue = true;
	int size, choice;
	string element; //change
	string topElement; //change
	bool empty, full;
	string* arrayPointer; //change

	cout << "Size of Stack: " << "\n";
	cin >> size;
	Stack<string>* myArray = new Stack<string>(size); //change
	do
	{
		cout << R"(
1. Push
2. Pop
3. Top
4. isEmpty
5. isFull
6. Print
7. Exit
)";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Type element to push: ";
			cin >> element;
			myArray->push(element);
			break;
		case 2:
			myArray->pop();
			break;
		case 3:
			topElement = myArray->peek();
			if (topElement == "") { //change depending on type
				cout << "Stack is empty.\n";
			}
			else {
				cout << "Top element is: " << topElement << "\n";
			}
			break;
		case 4:
			empty = myArray->isEmpty();
			if (empty) {
				cout << "Stack is empty.\n";
			}
			else {
				cout << "Stack is not empty.\n";
			}
			break;
		case 5:
			full = myArray->isFull();
			if (full) {
				cout << "Stack is full.\n";
			}
			else {
				cout << "Stack is not full.\n";
			}
			break;
		case 6:
			arrayPointer = myArray->print();
			for (int i = 0; i <= myArray->top; i++){
				cout << arrayPointer[i]<<"  ";
			}
			cout << "\n";
			break;
		case 7:
			breakTrue = false;
			break;
		default:
			cout << "Choose from 1-7\n";
			break;
		}
	} while (breakTrue);
	delete myArray;
	myArray = nullptr;
}
