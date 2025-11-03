#include <iostream>
using namespace std;

template <typename T>
class Stack {
    class Node {
    public:
        T value;
        Node* next;
        Node(T v) {
            value = v;
            next = NULL;
        }
    };
    Node* top;
public:
    Stack() 
    {
        top = NULL;
    }
    void push(T k) {
        Node* ptr = new Node(k);
        ptr->next = top;
        top = ptr;
    }
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    T peek() {
        if (top == NULL) return T();
            return top->value;
    }
    void display() {
        if (top == NULL) 
        {
            cout << "Empty\n";
            return;
        }
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

