#include <iostream>
using namespace std;

template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    T* minArr;
    int topIndex;
    int minTop;
    int maxSize;

public:
    myStack(int size) {
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
            cout << "Stack is Empty\n";
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
            cout << "Stack is Empty\n";
            return T();
        }
        return minArr[minTop];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }

        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~myStack() {
        delete[] arr;
        delete[] minArr;
    }
};

int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    myStack<int> s(size);

    int choice, value;

    do {
        cout << "\n1. Push element\n";
        cout << "2. Pop element\n";
        cout << "3. Show top element\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Check if stack is full\n";
        cout << "6. Display stack elements\n";
        cout << "7. Show minimum element\n";
        cout << "8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            cout << "Popped: " << s.pop() << endl;
            break;

        case 3:
            cout << "Top: " << s.top() << endl;
            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack is Empty\n";
            else
                cout << "Stack is NOT Empty\n";
            break;

        case 5:
            if (s.isFull())
                cout << "Stack is Full\n";
            else
                cout << "Stack is NOT Full\n";
            break;

        case 6:
            s.display();
            break;

        case 7:
            cout << "Minimum Element: " << s.getMin() << endl;
            break;

        case 8:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 8);

    return 0;
}