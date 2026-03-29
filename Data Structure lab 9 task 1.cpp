#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;
    
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    
    bool isEmpty() {
        return front == -1 || front > rear;
    }
    
    bool isFull() {
        return rear == MAX_SIZE - 1;
    }
    
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue." << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = data;
        cout << "Element " << data << " enqueued successfully." << endl;
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return;
        }
        cout << "Element " << arr[front] << " dequeued successfully." << endl;
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, data;
    
    do {
        cout << "\n=== MENU DRIVEN QUEUE ===" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> data;
                q.enqueue(data);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);
    
    return 0;
}
