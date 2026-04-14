
#include <iostream>
#include "AbstractQueue.h"
using namespace std;

template <typename T>
class myQueue : public AbstractQueue<T> {
private:
    T* arr;
    int frontIndex;
    int rearIndex;
    int size;
    int capacity;

public:
    myQueue(int cap) {
        capacity = cap;
        arr = new T[capacity];
        frontIndex = 0;
        rearIndex = -1;
        size = 0;
    }

    void enQueue(T value) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }
        rearIndex++;
        arr[rearIndex] = value;
        size++;
    }

    T deQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        T value = arr[frontIndex];
        frontIndex++;
        size--;
        return value;
    }

    T front() const {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[frontIndex];
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~myQueue() {
        delete[] arr;
    }
};

