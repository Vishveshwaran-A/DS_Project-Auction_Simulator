#pragma once 
#include <iostream>
#include<fstream>
#include "institutes.hpp"
using namespace std;
#define N 100
template <typename T>
class BinaryHeap {
    T arr[N];
    int size;

public:
    BinaryHeap() { size = 0; }

    bool isFull() { return size == N - 1; }
    bool isEmpty() { return size == 0; }
    
    T getMin()
    {  
           return arr[1];
    }
    void insert(T k) {
        if (isFull()) {
            cout << "Priority Queue is Full.\n";
            return;
        }
        int i;
        for (i = ++size; i / 2 > 0 && arr[i / 2] > k; i /= 2)
            arr[i] = arr[i / 2];
        arr[i] = k;
    }

    T deleteMin() {
        if (isEmpty()) {
            cout << "Priority Queue is Empty.\n";
            return T();  // default object
        }
        T min = arr[1];
        T last = arr[size--];
        int child;
        int i;
        for (i = 1; i * 2 <= size; i = child) {
            child = i * 2;
            if (child != size && arr[child + 1] < arr[child])
                child++;
            if (last > arr[child])
                arr[i] = arr[child];
            else
                break;
        }
        arr[i] = last;
        return min;
    }

    void decreaseKey(int i, double x) {
        if (i < 1 || i > size) {
            cout << "Index out of Range.\n";
            return;
        }
        arr[i] -= x;  // requires operator-=(int)
        for (; i / 2 > 0 && arr[i / 2] > arr[i]; i /= 2) {
            T t = arr[i / 2];
            arr[i / 2] = arr[i];
            arr[i] = t;
        }
    }

    void increaseKey(int i, double x) 
    {
        if (i < 1 || i > size) 
        {
            cout << "Index out of Range.\n";
            return;
        }
        arr[i] += x;  
        int child;
        for (; 2 * i <= size; i = child) {
            child = i * 2;
            if (child != size && arr[child + 1] < arr[child])
                child++;
            if (arr[i] > arr[child]) {
                T t = arr[child];
                arr[child] = arr[i];
                arr[i] = t;
            } else
                break;
        }
    }

    void Delete(int k) {
        if (k < 1 || k > size) {
            cout << "Index out of Range.\n";
            return;
        }
        decreaseKey(k, arr[k].getAid() + 1e20); 
        deleteMin();
    }


    
    void display() {
    if (isEmpty()) {
        cout << "Priority Queue is Empty.\n\n";
        return;
    }
    for (int i = 1; i <= size; i++){
          printf("%02d  ",i);
          cout << arr[i] << "\n";
    }
    cout << endl;
    }

    void saveHeap(string filename) 
    {
        ofstream out(filename, ios::trunc);  
        if (!out) {
            cout << "Error opening file: " << filename << endl;
            return;
        }

        out << size << "\n";              
        for (int i = 1; i <= size; i++)
            out << arr[i] << "\n";        

        out.close();
        
    }

    void loadHeap(string filename) 
    {
        ifstream in(filename);
        if (!in) {
            cout << "Error opening file: " << filename << endl;
            return;
        }

        int fileSize;
        in >> fileSize;
        if(fileSize >= N) fileSize = N-1;   
        size = fileSize;

        for (int i = 1; i <= size; i++)
            in >> arr[i];                   

        in.close();
        
    }

    
};

/*  int main() {
    int choice;
    BinaryHeap<Institute> b;
    b.loadHeap("Institutes.dat");
    cout << "\n=== Menu ===\n";
    cout << "1. Insert\n";
    cout << "2. DeleteMin\n";
    cout << "3. DecreaseKey\n";
    cout << "4. IncreaseKey\n";
    cout << "5. Delete\n";
    cout << "6. Display\n";
    cout << "-1. Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Institute x;
                cin >> x;
                b.insert(x);
                break;
            }
            case 2: {
                Institute x = b.deleteMin();
                cout << "Minimum element " << x << " is deleted\n";
                break;
            }
            case 3: {
                int idx, val;
                cout << "Enter index and value to decrease: ";
                cin >> idx >> val;
                b.decreaseKey(idx, val);
                break;
            }
            case 4: {
                int idx, val;
                cout << "Enter index and value to increase: ";
                cin >> idx >> val;
                b.increaseKey(idx, val);
                break;
            }
            case 5: {
                int idx;
                cout << "Enter index to delete: ";
                cin >> idx;
                b.Delete(idx);
                break;
            }
            case 6:
                b.display();
                break;
            case -1:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != -1);
    b.saveHeap("Institutes.dat");

    return 0;
}
*/