#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    int size;
    int *arr;
    int front, rear;
    int count;

    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];

        front = 0;
        rear = 0;
        count = 0;
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;

        arr[rear] = value;
        rear = (rear + 1) % size;
        count++;

        return true;
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;

        front = (front + 1) % size;
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty())
            return -1;

        return arr[front];
    }
    
    int Rear() {
        if (isEmpty())
            return -1;

        int index = (rear - 1 + size) % size;
        return arr[index];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};

int main(){
    MyCircularQueue queue(5);
    queue.enQueue(1);
    queue.enQueue(3);
    cout<<queue.Front();

    return 0;
}