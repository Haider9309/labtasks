

#include "AbstractStack.h"
#include <iostream>
using namespace std;

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    int topIndex;
    int maxSize;

public:
    myStack(int size);
    void push(T value);
    T pop();
    T top() const;
    bool isEmpty() const;
    bool isFull() const;
    void display() const;
    ~myStack();
};

