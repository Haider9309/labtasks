
#include "Stack.h"

template <typename T>
class QueueUsingStack {
private:
    Stack<T> s1;
    Stack<T> s2;
    int capacity;

public:
    QueueUsingStack(int cap) : s1(cap), s2(cap) {
        capacity = cap;
    }

    void enqueue(T value) {
        if (s1.isFull()) {
            cout << "Queue is Full\n";
            return;
        }
        s1.push(value);
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }

        return s2.pop();
    }

    T front() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }

        return s2.top();
    }

    bool isEmpty() {
        return s1.isEmpty() && s2.isEmpty();
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        Stack<T> temp1 = s1;
        Stack<T> temp2 = s2;

        if (!temp2.isEmpty()) {
            while (!temp2.isEmpty()) {
                cout << temp2.pop() << " ";
            }
        }

        T tempArr[1000];
        int i = 0;

        while (!temp1.isEmpty()) {
            tempArr[i++] = temp1.pop();
        }

        for (int j = i - 1; j >= 0; j--) {
            cout << tempArr[j] << " ";
        }

        cout << endl;
    }
};

