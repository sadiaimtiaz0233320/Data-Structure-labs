#include <iostream>
#include <string>
using namespace std;

// ================= PROFILE CLASS =================
class Profile {
private:
    int id;            // User ID
    string name;       // User Name
    string gender;     // User Gender
    int age;           // User Age
    string email;      // User Email
    string interest;   // User Interest
    string dob;        // Date of Birth

public:
    // Constructor to initialize profile data
    Profile(int i, string n, string g, int a, string e, string in, string d) {
        id = i;
        name = n;
        gender = g;
        age = a;
        email = e;
        interest = in;
        dob = d;
    }

    // Getter function to return ID
    int getID() {
        return id;
    }

    // Getter function to return Name
    string getName() {
        return name;
    }

    // Function to update profile information
    void updateProfile() {
        cout << "Enter New Name: ";
        cin >> name;

        cout << "Enter Gender: ";
        cin >> gender;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Email: ";
        cin >> email;

        cout << "Enter Interest: ";
        cin >> interest;

        cout << "Enter Date of Birth: ";
        cin >> dob;
    }

    // Function to display profile information
    void display() {
        cout << "\nID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Age: " << age << endl;
        cout << "Email: " << email << endl;
        cout << "Interest: " << interest << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "---------------------------\n";
    }
};

// ================= NODE CLASS =================
class Node {
public:
    Profile data;   // Each node stores a Profile object
    Node* next;     // Pointer to next node

    // Constructor
    Node(Profile p) : data(p) {
        next = NULL;   // Initially next is NULL
    }
};

// ================= PORTAL CLASS (LINKED LIST) =================
class Portal {
private:
    Node* head;   // Head pointer of linked list

public:
    // Constructor
    Portal() {
        head = NULL;  // Initially list is empty
    }

    // ================= INSERT PROFILE =================
    // Insert profile at end of list
    void InsertProfile(Profile p) {

        Node* newNode = new Node(p);  // Create new node

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

        temp->next = newNode;  // Attach new node at end
    }

    // ================= UPDATE PROFILE =================
    // Update profile using ID
    void UpdateProfile(int id) {

        Node* temp = head;

        // Traverse list
        while (temp != NULL) {

            if (temp->data.getID() == id) {
                temp->data.updateProfile();  // Call update function
                cout << "Profile Updated Successfully!\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Profile not found!\n";
    }

    // ================= DELETE PROFILE =================
    // Delete profile using Name
    void DeleteProfile(string name) {

        if (head == NULL) {
            cout << "No profiles available!\n";
            return;
        }

        // If first node matches
        if (head->data.getName() == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Profile Deleted!\n";
            return;
        }

        Node* temp = head;

        // Search node before the one to delete
        while (temp->next != NULL && temp->next->data.getName() != name) {
            temp = temp->next;
        }

        // If not found
        if (temp->next == NULL) {
            cout << "Profile not found!\n";
            return;
        }

        Node* delNode = temp->next;       // Node to delete
        temp->next = temp->next->next;    // Skip that node
        delete delNode;                   // Free memory

        cout << "Profile Deleted!\n";
    }

    // ================= SEARCH PROFILE =================
    // Search profile by name
    void searchProfile(string name) {

        Node* temp = head;

        while (temp != NULL) {

            if (temp->data.getName() == name) {
                cout << "\nProfile Found:\n";
                temp->data.display();
                return;
            }

            temp = temp->next;
        }

        cout << "Profile not found!\n";
    }

    // ================= DISPLAY ALL =================
    // Display all profiles
    void Display() {

        if (head == NULL) {
            cout << "No profiles available!\n";
            return;
        }

        Node* temp = head;

        while (temp != NULL) {
            temp->data.display();  // Call display function
            temp = temp->next;
        }
    }
};

// ================= MAIN FUNCTION =================
int main() {

    Portal portal;  // Create portal object
    int choice;

    // Menu driven loop
    do {

        cout << "\n===== SOCIAL MEDIA PORTAL =====\n";
        cout << "1) Add New Profile\n";
        cout << "2) Update Profile\n";
        cout << "3) Delete Profile\n";
        cout << "4) Search Profile\n";
        cout << "5) Display All\n";
        cout << "6) Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        // ========== ADD PROFILE ==========
        if (choice == 1) {

            int id, age;
            string name, gender, email, interest, dob;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Gender: ";
            cin >> gender;

            cout << "Enter Age: ";
            cin >> age;

            cout << "Enter Email: ";
            cin >> email;

            cout << "Enter Interest: ";
            cin >> interest;

            cout << "Enter Date of Birth: ";
            cin >> dob;

            Profile p(id, name, gender, age, email, interest, dob);

            portal.InsertProfile(p);  // Insert into linked list
        }

        // ========== UPDATE PROFILE ==========
        else if (choice == 2) {

            int id;
            cout << "Enter ID to Update: ";
            cin >> id;

            portal.UpdateProfile(id);
        }

        // ========== DELETE PROFILE ==========
        else if (choice == 3) {

            string name;
            cout << "Enter Name to Delete: ";
            cin >> name;

            portal.DeleteProfile(name);
        }

        // ========== SEARCH PROFILE ==========
        else if (choice == 4) {

            string name;
            cout << "Enter Name to Search: ";
            cin >> name;

            portal.searchProfile(name);
        }

        // ========== DISPLAY ALL ==========
        else if (choice == 5) {

            portal.Display();
        }

        // ========== EXIT ==========
        else if (choice == 6) {

            cout << "Exiting Program...\n";
        }

        else {
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);  // Loop until user selects Exit

    return 0;
}
