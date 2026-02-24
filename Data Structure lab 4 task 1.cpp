#include <iostream>
#include <string>
using namespace std;

// ================= MOBILE CLASS =================
class Mobile {
private:
    string name;        // Brand name of mobile
    int unitsOnHand;    // Number of mobiles available in store
    double price;       // Retail price of mobile

public:
    // Constructor to initialize values
    Mobile(string n, int u, double p) {
        name = n;
        unitsOnHand = u;
        price = p;
    }

    // Setter function to set brand name
    void setName(string n) {
        name = n;
    }

    // Setter function to set units
    void setUnits(int u) {
        unitsOnHand = u;
    }

    // Setter function to set price
    void setPrice(double p) {
        price = p;
    }

    // Getter function to get brand name
    string getName() {
        return name;
    }

    // Getter function to get units
    int getUnits() {
        return unitsOnHand;
    }

    // Getter function to get price
    double getPrice() {
        return price;
    }
};

// ================= NODE CLASS =================
class Node {
public:
    Mobile data;   // Each node stores a Mobile object
    Node* next;    // Pointer to next node

    // Constructor
    Node(Mobile m) : data(m) {
        next = NULL;   // Initially next is NULL
    }
};

// ================= STORE CLASS (LINKED LIST) =================
class Store {
private:
    Node* head;   // Pointer to first node

public:
    // Constructor
    Store() {
        head = NULL;  // Initially list is empty
    }

    // ================= INSERT AT START =================
    void insertAtStart(Mobile m) {
        Node* newNode = new Node(m); // Create new node
        newNode->next = head;        // New node points to old head
        head = newNode;              // Head becomes new node
    }

    // ================= INSERT AT END =================
    void insertAtEnd(Mobile m) {
        Node* newNode = new Node(m); // Create new node

        // If list is empty
        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        // Traverse until last node
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode; // Last node points to new node
    }

    // ================= INSERT IN BETWEEN =================
    // Insert new mobile after a specific brand
    void insertAfter(string brand, Mobile m) {
        Node* temp = head;

        // Search for given brand
        while (temp != NULL && temp->data.getName() != brand) {
            temp = temp->next;
        }

        // If brand not found
        if (temp == NULL) {
            cout << "Brand not found!\n";
            return;
        }

        Node* newNode = new Node(m);
        newNode->next = temp->next; // New node points to next node
        temp->next = newNode;      // Previous node points to new node
    }

    // ================= DELETE FROM START =================
    void deleteFromStart() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;   // Store current head
        head = head->next;   // Move head to next node
        delete temp;         // Delete old head
    }

    // ================= DELETE FROM END =================
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        // If only one node
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        // Traverse to second last node
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;   // Delete last node
        temp->next = NULL;   // Make second last node last
    }

    // ================= DELETE IN BETWEEN =================
    // Delete mobile by brand name
    void deleteMobile(string brand) {

        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        // If first node contains the brand
        if (head->data.getName() == brand) {
            deleteFromStart();
            return;
        }

        Node* temp = head;

        // Search for node before the one to delete
        while (temp->next != NULL && temp->next->data.getName() != brand) {
            temp = temp->next;
        }

        // If brand not found
        if (temp->next == NULL) {
            cout << "Brand not found!\n";
            return;
        }

        Node* delNode = temp->next;      // Node to delete
        temp->next = temp->next->next;   // Skip that node
        delete delNode;                  // Delete it
    }

    // ================= DISPLAY FUNCTION =================
    void display() {
        if (head == NULL) {
            cout << "No mobiles in store!\n";
            return;
        }

        Node* temp = head;

        // Traverse whole list
        while (temp != NULL) {
            cout << "Brand: " << temp->data.getName() << endl;
            cout << "Units: " << temp->data.getUnits() << endl;
            cout << "Price: " << temp->data.getPrice() << endl;
            cout << "----------------------\n";
            temp = temp->next;
        }
    }
};

// ================= MAIN FUNCTION =================
int main() {

    Store s;  // Create store object

    // Create mobile objects
    Mobile m1("Samsung", 10, 150000);
    Mobile m2("iPhone", 5, 300000);
    Mobile m3("Infinix", 20, 40000);
    Mobile m4("Oppo", 15, 60000);

    // Insert at start
    s.insertAtStart(m1);

    // Insert at end
    s.insertAtEnd(m2);

    // Insert in between (after Samsung)
    s.insertAfter("Samsung", m3);

    cout << "\nMobiles After Insertions:\n";
    s.display();

    // Delete from start
    s.deleteFromStart();

    // Delete from end
    s.deleteFromEnd();

    // Delete specific brand
    s.deleteMobile("Infinix");

    cout << "\nMobiles After Deletions:\n";
    s.display();

    return 0;
}
