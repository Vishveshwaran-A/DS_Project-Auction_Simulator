#pragma once 
#include <iostream>
#include <fstream>
#include "property.hpp"
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
    void enqueue(T k) 
    {
        Node* ptr = new Node(k);
        if (rear == NULL) {
            front = rear = ptr;
            return;
        }
        rear->next = ptr;
        rear = rear->next;
    }
    bool isEmpty() 
    {
    return (front == NULL);
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
    }
    T peek() 
    {   
        T t;
        if (isEmpty()) 
        {
            cout << "Queue is empty\n";
            return t; 
        }
        return front->value;
    }
    
    void display() 
    {
        if (front == NULL) 
        {
            cout << "Empty\n";
            return;
        }
        Node* temp = front;
        while (temp != NULL) 
        {
            cout << temp->value <<endl;
            temp = temp->next;
        }
    }
    void saveQueue(string filename) 
    {
    ofstream outf(filename);
     if (!outf) 
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }
    while (!isEmpty()) 
    {
        outf << peek() << "\n";  
        dequeue();
    }
     outf.close();
   }

   Queue<T> loadQueue(string filename) 
   {
    Queue<Property> q;    
    ifstream in(filename);
    T temp;
    while (in >> temp) 
        enqueue(temp);
    in.close();
   
   }

};




/*int main() {
    Queue<Property> q=loadQueue("./property.dat");
    Property val;
    int ch;
     
    cout << "1. Enqueue\n2. Dequeue\n3. Display\nAny other key to Exit\n";
    while (true) {
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            default:
                cout << "Exiting program.\n";
                saveQueue(q,"./property.dat");
                return 0;
        }
    }
}*/
