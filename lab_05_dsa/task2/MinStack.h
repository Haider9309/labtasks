

#include "AbstractStack.h"
#include <iostream>
using namespace std;

template <typename T>
class MinStack : public AbstractStack<T> {
private:
    T* arr;
    T* minArr;
    int topIndex;
    int minTop;
    int maxSize;

public:
    MinStack(int size) {
        maxSize = size;
        arr = new T[maxSize];
        minArr = new T[maxSize];
        topIndex = -1;
        minTop = -1;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }

        topIndex++;
        arr[topIndex] = value;

        if (minTop == -1 || value <= minArr[minTop]) {
            minTop++;
            minArr[minTop] = value;
        }
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return T();
        }

        T value = arr[topIndex];

        if (value == minArr[minTop]) {
            minTop--;
        }

        topIndex--;
        return value;
    }

    T top() const {
        if (isEmpty()) {
            cout << "Stack Empty\n";
            return T();
        }
        return arr[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == maxSize - 1;
    }

    T getMin() const {
        if (minTop == -1) {
            cout << "Stack Empty\n";
            return T();
        }
        return minArr[minTop];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack Empty\n";
            return;
        }

        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~MinStack() {
        delete[] arr;
        delete[] minArr;
    }
};

