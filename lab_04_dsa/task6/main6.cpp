#include <iostream>
#include "PackageQueue.h"
using namespace std;

int main() {
    int capacity;
    cout << "Enter capacity: ";
    cin >> capacity;

    PackageQueue q(capacity);

    int choice;

    do {
        cout << "\n1. Add Package\n2. Deliver Package\n3. Check Front\n4. Display\n5. Time Check Delivery\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, startTime, endTime;
            string address;

            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Address: ";
            cin >> address;
            cout << "Enter start time: ";
            cin >> startTime;
            cout << "Enter end time: ";
            cin >> endTime;

            q.enqueue(id, address, startTime, endTime);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            q.front();
        }
        else if (choice == 4) {
            q.display();
        }
        else if (choice == 5) {
            int currentTime;
            cout << "Enter current time: ";
            cin >> currentTime;
            q.timeToDeliver(currentTime);
        }

    } while (choice != 0);

    return 0;
}