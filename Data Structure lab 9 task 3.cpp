#include <iostream>
using namespace std;

#define MAX_SIZE 100

class CountQueue {
private:
    int arr[MAX_SIZE];
    int front, rear;
    int count;  // To keep track of number of elements
    
public:
    CountQueue() {
        front = -1;
        rear = -1;
        count = 0;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == MAX_SIZE;
    }
    
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = data;
        count++;
        cout << "Enqueued: " << data << endl;
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front++;
        count--;
        if (front > rear) {
            front = rear = -1;
        }
    }
    
    int getCount() {
        return count;
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
        cout << "Number of elements in queue: " << getCount() << endl;
    }
};

int main() {
    CountQueue q;
    int choice, data;
    
    cout << "=== QUEUE WITH ELEMENT COUNT ===" << endl;
    
    // Test the queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();  // Should show 3 elements
    
    q.dequeue();
    q.display();  // Should show 2 elements
    
    cout << "Total elements: " << q.getCount() << endl;
    
    return 0;
}
