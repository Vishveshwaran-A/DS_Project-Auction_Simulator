#pragma once 
#include <iostream>
#include <fstream>
#include "member.hpp"
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
    

public:
    Node* head;
    LinkedList()
    {
        head=NULL;
    }
    

    int search(int k) {
        int ind = 0;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->value == k) return ind;
            temp = temp->next;
            ind++;
        }
        return -1;
    }

    T getValue(int index) 
    {
        Node* temp = head;
        int i = 0;
        while (temp != NULL) {
            if (i == index)
                return temp->value;
            temp = temp->next;
            i++;
        }
        return T();
        
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

    void middle_delete(int ind) 
    {
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
        int i=1;
        while (temp != NULL) {
            printf("%02d   ",i);
            cout <<" "<< temp->value << "\n";
            temp = temp->next;
            i++;
        }
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
                if (next->value > curr->value) {
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

    void saveLinkedList(string filename) 
   {
    ofstream out(filename);
    if (!out) 
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    auto temp= head;  
    while (temp !=NULL) 
    {
        out << temp->value << "\n";  
        temp = temp->next;
    }

    out.close();
    }

    LinkedList<T> loadLinkedList(string filename) 
   {
    ifstream in(filename);
    T temp;
    while (in >> temp) 
        end_insert(temp);
    in.close();

   }
};







/*int main() {
    LinkedList<Member> l=loadLinkedList("member.dat");
    Member value;

    int choice,index;
    cout << "\nMenu:\n";
    cout << "1. Insert at beginning\n";
    cout << "2. Insert at middle\n";
    cout << "3. Insert at end\n";
    cout << "4. Delete from beginning\n";
    cout << "5. Delete from middle\n";
    cout << "6. Delete from end\n";
    cout << "7. Print list\n";
    cout << "8. Get length\n";
    cout << "9. Search value\n";
    cout << "10. Reverse list\n";
    cout << "11. Sort list\n\n";

    while (1) {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                l.begin_insert(value);
                cout << "\n";
                break;
            case 2:
                cout << "Enter index to insert at (starting from 0, not including head): ";
                cin >> index;
                cout << "Enter value to insert: ";
                cin >> value;
                l.middle_insert(value, index);
                cout << "\n";
                break;
            case 3:
                cout << "Enter value to insert at end: ";
                cin >> value;
                l.end_insert(value);
                cout << "\n";
                break;
            case 4:
                l.begin_delete();
                //cout << "Deleted from beginning.\n\n";
                break;
            case 5:
                cout << "Enter index to delete from (not 0): ";
                cin >> index;
                l.middle_delete(index);
                //cout << "Deleted from middle.\n\n";
                break;
            case 6:
                l.end_delete();
                //cout << "Deleted from end.\n\n";
                break;
            case 7:
                l.print();
                cout << "\n";
                break;
            case 8:
                cout << "Length of list: " << l.length() << "\n\n";
                break;
            case 9:
                cout << "Enter value to search: ";
                cin >> value;
                //cout << "Index: " << l.search(value) << "\n\n";
                break;
            case 10:
                l.reverse();
                cout << "List reversed.\n\n";
                break;
            case 11:
                //l.sort();
                cout << "List sorted.\n\n";
                break;
            default:
                cout << "Invalid choice. Exiting.\n";
                saveLinkedList(l,"member.dat");
                return 0;
        }
    }
}*/
