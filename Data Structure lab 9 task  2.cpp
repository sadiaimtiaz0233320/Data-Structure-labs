#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedListQueue {
private:
    Node* front;
    Node* rear;
    
public:
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
    }
    
    bool isEmpty() {
        return front == nullptr;
    }
    
    // Insert at rear
    void enqueue(int data) {
        Node* newNode = new Node(data);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Element " << data << " inserted at rear successfully." << endl;
    }
    
    // Delete from front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot delete from front." << endl;
            return;
        }
        
        Node* temp = front;
        cout << "Element " << temp->data << " deleted from front successfully." << endl;
        
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
        }
        
        delete temp;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        cout << "Queue elements (front to rear): ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    ~LinkedListQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    LinkedListQueue q;
    int choice, data;
    
    do {
        cout << "\n=== LINKED LIST QUEUE ===" << endl;
        cout << "1. Insert at rear (Enqueue)" << endl;
        cout << "2. Delete from front (Dequeue)" << endl;
        cout << "3. Display all elements" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
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
