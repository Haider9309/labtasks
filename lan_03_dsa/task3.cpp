#include <iostream>
using namespace std;

class myCarStack {
private:
    string arr[8];
    int top;

public:
    myCarStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 7;
    }

    void push(string car) {
        if (isFull()) {
            cout << "Parking Full\n";
            return;
        }
        top++;
        arr[top] = car;
        cout << "Car Parked: " << car << endl;
    }

    string pop() {
        if (isEmpty()) {
            cout << "Parking Empty\n";
            return "";
        }
        string car = arr[top];
        top--;
        return car;
    }

    string peek() {
        if (isEmpty()) {
            return "";
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "No cars parked\n";
            return;
        }

        cout << "Cars in Parking (Top to Bottom):\n";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }

    int count() {
        return top + 1;
    }

    bool search(string car) {
        for (int i = 0; i <= top; i++) {
            if (arr[i] == car) {
                return true;
            }
        }
        return false;
    }

    void removeCar(string car) {
        if (isEmpty()) {
            cout << "Parking Empty\n";
            return;
        }

        myCarStack temp;
        bool found = false;

        while (!isEmpty()) {
            string current = pop();

            if (current == car) {
                cout << "Car Removed: " << car << endl;
                found = true;
                break;
            }
            else {
                temp.push(current);
            }
        }

        if (!found) {
            cout << "Car not found\n";
        }

        while (!temp.isEmpty()) {
            push(temp.pop());
        }
    }
};

int main() {
    myCarStack parking;
    int choice;
    string car;

    do {
        cout << "\n1. Park Car\n";
        cout << "2. Remove Car\n";
        cout << "3. Show Top Car\n";
        cout << "4. Show All Cars\n";
        cout << "5. Total Cars\n";
        cout << "6. Search Car\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter car number: ";
            cin >> car;
            parking.push(car);
            break;

        case 2:
            cout << "Enter car number to remove: ";
            cin >> car;
            parking.removeCar(car);
            break;

        case 3:
            cout << "Top Car: " << parking.peek() << endl;
            break;

        case 4:
            parking.display();
            break;

        case 5:
            cout << "Total Cars: " << parking.count() << endl;
            break;

        case 6:
            cout << "Enter car number to search: ";
            cin >> car;
            if (parking.search(car))
                cout << "Car Found\n";
            else
                cout << "Car Not Found\n";
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 7);

    return 0;
}