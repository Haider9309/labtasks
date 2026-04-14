#include <iostream>
#include "QueueUsingStack.h"
using namespace std;

int main() {
    int size;
    cout << "Enter queue size: ";
    cin >> size;

    QueueUsingStack<int> q(size);

    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
        }
        else if (choice == 2) {
            int val = q.dequeue();
            if (val != -1)
                cout << "Removed: " << val << endl;
        }
        else if (choice == 3) {
            int val = q.front();
            if (val != -1)
                cout << "Front: " << val << endl;
        }
        else if (choice == 4) {
            q.display();
        }

    } while (choice != 0);

    return 0;
}