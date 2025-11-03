#include <iostream>
using namespace std;

template <typename T>
class Queue 
{
    class Node {
    public:
        T value;
        Node* next;
        Node(T v) {
            value = v;
            next = NULL;
        }
    };
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = NULL;
    }
    void enqueue(T k) {
        Node* ptr = new Node(k);
        if (rear == NULL) {
            front = rear = ptr;
            return;
        }
        rear->next = ptr;
        rear = rear->next;
    }
    void dequeue() {
        if (front == NULL) {
            cout << "Queue underflow.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
    }
    void display() {
        if (front == NULL) {
            cout << "Empty\n";
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

