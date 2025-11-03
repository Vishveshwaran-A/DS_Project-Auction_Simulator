#include <iostream>
using namespace std;
template <typename T>
class LinkedList 
{
    
    class Node 
    {  public:
        T value;
        Node* next;
        Node(T v)
       {
        value=v;
        next=NULL;
       }
    };
    Node* head;

public:
    LinkedList()
    {
        head=NULL;
    }

    void begin_insert(T k) 
    {
        Node* ptr = new Node(k);
        ptr->next = head;
        head = ptr;
    }

    void middle_insert(T k, int ind) {
        if (ind == 0 || head == NULL) return;
        Node* temp = head;
        for (int i = 1; i < ind; i++) {
            if (temp->next == NULL) return;
            temp = temp->next;
        }
        Node* ptr = new Node(k);
        ptr->next = temp->next;
        temp->next = ptr;
    }

    void end_insert(T k) {
        Node* ptr = new Node(k);
        if (head == NULL) {
            head = ptr;
            return;
        }
        Node* temp = head;
        while (temp->next) 
          temp = temp->next;
        temp->next = ptr;
    }

    void begin_delete() {
        if (head == NULL) 
           return;
        Node* t = head;
        head = head->next;
        delete t;
    }

    void middle_delete(int ind) {
        if (ind == 0 || head == NULL) return;
        Node* temp = head;
        for (int i = 1; i < ind; i++) {
            if (temp->next == NULL) return;
            temp = temp->next;
        }
        if (temp->next == NULL) return;
        Node* t = temp->next;
        temp->next = t->next;
        delete t;
    }

    void end_delete() {
        if (head == NULL) return;
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next) {
            prev = temp;
            temp = temp->next;
        }
        delete temp;
        prev->next = NULL;
    }

    void print() {
        if (head == NULL) {
            cout << "Empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int length() {
        int l = 0;
        Node* temp = head;
        while (temp != NULL) {
            l++;
            temp = temp->next;
        }
        return l;
    }

    int search(T k) {
        int ind = 0;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->value == k) return ind;
            temp = temp->next;
            ind++;
        }
        return -1;
    }

    void reverse() {
        if (head == NULL || head->next == NULL) return;
        Node* one = head;
        Node* two = head->next;
        head->next = NULL;
        while (two != NULL) {
            Node* t = two->next;
            two->next = one;
            one = two;
            two = t;
        }
        head = one;
    }

    void sort() {
        int swapped;
        if (head == NULL) return;
        do {
            swapped = 0;
            Node* prev = NULL;
            Node* curr = head;
            Node* next = head->next;
            while (next != NULL) {
                if (curr->value > next->value) {
                    if (prev == NULL) head = next;
                    else prev->next = next;
                    curr->next = next->next;
                    next->next = curr;
                    Node* t = curr;
                    curr = next;
                    next = t;
                    swapped = 1;
                }
                prev = curr;
                curr = next;
                next = next->next;
            }
        } while (swapped);
    }
};

