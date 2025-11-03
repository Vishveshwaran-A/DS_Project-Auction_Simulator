#pragma once 
#include <iostream>
#include "bid.hpp"
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
        if (top == NULL) 
            return T();
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
            cout << temp->value << "\n";
            temp = temp->next;
        }
        cout << endl;
    }
};



/*int main() {
    Stack<Bid> st;
    Bid val;
    int ch;
    
    cout << "1. Push\n2. Pop\n3. Peek\n4. Display\nAny other key to Exit\n";
    while (true) {
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cin >> val;
                st.push(val);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                val = st.peek();
                cout << "Top element: " << val << endl;
                break;
            case 4:
                st.display();
                break;
            default:
                cout << "Exiting program.\n";
                return 0;
        }
    }
}*/
