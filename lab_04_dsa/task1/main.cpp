#include <iostream>
#include "myQueue.h"
using namespace std;

int main() {
    int capacity;
    cout << "Enter queue size: ";
    cin >> capacity;

    myQueue<int> q(capacity);

    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Check Empty\n5. Check Full\n6. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
        }
        else if (choice == 2) {
            int removed = q.deQueue();
            if (removed != -1)
                cout << "Removed: " << removed << endl;
        }
        else if (choice == 3) {
            int f = q.front();
            if (f != -1)
                cout << "Front: " << f << endl;
        }
        else if (choice == 4) {
            if (q.isEmpty())
                cout << "Queue is Empty\n";
            else
                cout << "Queue is NOT Empty\n";
        }
        else if (choice == 5) {
            if (q.isFull())
                cout << "Queue is Full\n";
            else
                cout << "Queue is NOT Full\n";
        }
        else if (choice == 6) {
            q.display();
        }

    } while (choice != 0);

    return 0;
}