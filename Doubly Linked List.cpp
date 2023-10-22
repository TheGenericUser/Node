#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }

    ~Node() {
    }
};

void insertAtHead(Node*& head, Node*& tail, int value) {
    Node* temp = new Node(value);
    if (head == nullptr) {
        head = temp;
        tail = head;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node*& head, Node*& tail, int value) {
    Node* temp = new Node(value);
    if (tail == nullptr) {
        tail = temp;
        head = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node*& head, Node*& tail, int position, int value) {
    if (position == 1) {
        insertAtHead(head, tail, value);
        return;
    }
    Node* temp = head;
    Node* insert = new Node(value);
    int start = 1;
    while (start < (position - 1)) {
        temp = temp->next;
        start++;
    }
    if (temp->next == nullptr) {
        insertAtTail(head, tail, value);
        return;
    }
    insert->next = temp->next;
    (temp->next)->prev = insert;
    insert->prev = temp;
    temp->next = insert;
}

void deleteNodePosition(Node*& head, Node*& tail, int position) {
    if (position == 1) {
        if (head->next == nullptr) {
            head = nullptr;
            tail = nullptr;
            delete head;
            delete tail;
            return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        return;
    }
    Node* current = head;
    Node* prev = current;
    int start = 1;
    while (start < position) {
        prev = current;
        current = current->next;
        start++;
    }
    if (current->next == nullptr) {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return;
    }
    prev->next = current->next;
    (current->next)->prev = prev;
    current->next = nullptr;
    current->prev = nullptr;
    delete current;
}

void reverse(Node* &head, Node* &tail) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->prev = next;
        current->next = prev;
        prev = current;
        current = next;
    }
    tail = head;
    head = prev;
}

void print(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty" << "\n";
        return;
    }
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int getLength(Node*& head) {
    Node* temp = head;
    int count = 0;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    // Node* head = new Node(90);
    Node* head = nullptr;
    Node* tail = head;
    insertAtHead(head, tail, 98);
    insertAtHead(head, tail, 99);
    insertAtTail(tail, tail, 909);
    insertAtPosition(head, tail, 2, 78); //can handle error, but dont have to. if head i null, then it'll just be segmentation fault
    insertAtPosition(head, tail, 1, 12);
    insertAtPosition(head, tail, 6, 78);
    deleteNodePosition(head, tail, 1);
    print(head);
    reverse(head, tail);
    print(head);
    cout<<"Length: " <<getLength(head)<<"\n";
    cout << head->value << " prev:" << head->prev << " next:" << head->next << "\n";
    cout << tail->value << " prev:" << tail->prev << " next:" << tail->next << "\n";
}