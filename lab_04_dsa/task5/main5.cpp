#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    int capacity;
    cout << "Enter max number of print jobs: ";
    cin >> capacity;

    Queue printer(capacity);

    int choice;
    string document_name;

    do {
        cout << "\n1. Add Print Job\n2. Print Document\n3. Check Front\n4. Display Jobs\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter document name: ";
            cin >> document_name;
            printer.enqueue(document_name);
        }
        else if (choice == 2) {
            printer.dequeue();
        }
        else if (choice == 3) {
            printer.front();
        }
        else if (choice == 4) {
            printer.display();
        }

    } while (choice != 0);

    return 0;
}