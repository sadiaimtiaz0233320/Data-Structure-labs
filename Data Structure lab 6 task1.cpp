#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBefore(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    }
    else {
        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    cout << "Node added at beginning\n";
}

// Insert at end
void insertAfter(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    }
    else {
        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    cout << "Node added at end\n";
}

// Delete node
void deleteNode(int value) {

    if (head == NULL) {
        cout << "List empty\n";
        return;
    }

    Node *temp = head, *prev = NULL;

    // delete first node
    if (temp->data == value) {

        while (temp->next != head)
            temp = temp->next;

        if (temp == head) {
            head = NULL;
        }
        else {
            temp->next = head->next;
            head = head->next;
        }

        cout << "Node deleted\n";
        return;
    }

    Node* curr = head->next;
    prev = head;

    while (curr != head && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->data == value) {
        prev->next = curr->next;
        cout << "Node deleted\n";
    }
}

// Display list
void display() {
    if (head == NULL) return;

    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {

    insertBefore(10);
    insertAfter(20);
    insertAfter(30);

    display();

    deleteNode(20);

    display();

}
