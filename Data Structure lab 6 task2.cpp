#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* head = NULL;

// Add employee
void addEmployee(string name) {

    Node* newNode = new Node();
    newNode->name = name;

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

    cout << "Employee added successfully\n";
}

// Search employee
void searchEmployee(string name) {

    Node* temp = head;

    do {
        if (temp->name == name) {
            cout << "Employee found\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Employee not found\n";
}

// Delete employee
void deleteEmployee(string name) {

    Node *temp = head, *prev;

    do {
        if (temp->name == name) {

            prev->next = temp->next;
            cout << "Employee deleted successfully\n";
            return;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != head);

}

// Update employee
void updateEmployee(string oldName, string newName) {

    Node* temp = head;

    do {
        if (temp->name == oldName) {

            temp->name = newName;
            cout << "Employee updated successfully\n";
            return;
        }

        temp = temp->next;

    } while (temp != head);
}

int main() {

    addEmployee("Ali");
    addEmployee("Sara");
    addEmployee("Ahmed");

    searchEmployee("Sara");

    updateEmployee("Sara","Ayesha");

    deleteEmployee("Ali");

}
