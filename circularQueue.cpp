
#include <bits/stdc++.h>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Insert an element
    void enqueue(int value) {
        if ((rear + 1) % SIZE == front) {
            cout << "Queue is Full\n";
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        arr[rear] = value;

        cout << value << " inserted\n";
    }

    // Delete an element
    void dequeue() {
        if (front == -1) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << arr[front] << " deleted\n";

        if (front == rear) {
            // Only one element was present
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    // Display the queue
    void display() {
        if (front == -1) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue: ";

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % SIZE;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}
