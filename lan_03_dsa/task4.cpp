#include <iostream>
using namespace std;

struct Action {
    char ch;
    int type;
};

class Stack {
private:
    Action arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(Action a) {
        if (top == 99) return;
        top++;
        arr[top] = a;
    }

    Action pop() {
        if (isEmpty()) return { '\0', 0 };
        return arr[top--];
    }

    void clear() {
        top = -1;
    }
};

int main() {
    Stack undoStack, redoStack;
    string text = "";
    int choice;
    char ch;

    do {
        cout << "\nCurrent Text: " << text << endl;

        cout << "1. Type Character\n";
        cout << "2. Delete Character\n";
        cout << "3. Undo\n";
        cout << "4. Redo\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter character: ";
            cin >> ch;

            text += ch;

            undoStack.push({ ch, 1 });
            redoStack.clear();
            break;

        case 2:
            if (text.length() == 0) {
                cout << "Nothing to delete\n";
                break;
            }

            ch = text[text.length() - 1];
            text.erase(text.length() - 1);

            undoStack.push({ ch, 2 });
            redoStack.clear();
            break;

        case 3:
            if (undoStack.isEmpty()) {
                cout << "Nothing to undo\n";
                break;
            }

            {
                Action a = undoStack.pop();

                if (a.type == 1) {
                    text.erase(text.length() - 1);
                }
                else if (a.type == 2) {
                    text += a.ch;
                }

                redoStack.push(a);
            }
            break;

        case 4:
            if (redoStack.isEmpty()) {
                cout << "Nothing to redo\n";
                break;
            }

            {
                Action a = redoStack.pop();

                if (a.type == 1) {
                    text += a.ch;
                }
                else if (a.type == 2) {
                    text.erase(text.length() - 1);
                }

                undoStack.push(a);
            }
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}