#include <iostream>
using namespace std;

// Structure for Doubly Linked List Node
struct Node
{
    int data;       // marks
    Node* next;     // pointer to next node
    Node* prev;     // pointer to previous node
};

Node* head = NULL; // head pointer

// Function to create list from user input
void createList(int n)
{
    Node *temp, *newNode;

    for(int i=0;i<n;i++)
    {
        newNode = new Node();   // create new node

        cout<<"Enter marks: ";
        cin>>newNode->data;

        newNode->next = NULL;
        newNode->prev = NULL;

        // if list empty
        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;   // connect previous node
            newNode->prev = temp;   // connect backward
            temp = newNode;
        }
    }
}

// Insert node at beginning
void addBeginning(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

    if(head != NULL)
        head->prev = newNode;

    head = newNode; // new node becomes head
}

// Insert after value 45
void addAfter45(int value)
{
    Node* temp = head;

    while(temp != NULL)
    {
        if(temp->data == 45) // find 45
        {
            Node* newNode = new Node();

            newNode->data = value;
            newNode->next = temp->next;
            newNode->prev = temp;

            if(temp->next != NULL)
                temp->next->prev = newNode;

            temp->next = newNode;

            return;
        }

        temp = temp->next;
    }

    cout<<"45 not found in list\n";
}

// Delete from beginning
void deleteBeginning()
{
    if(head == NULL)
    {
        cout<<"List Empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    delete temp;
}

// Delete node after 45
void deleteAfter45()
{
    Node* temp = head;

    while(temp != NULL)
    {
        if(temp->data == 45 && temp->next != NULL)
        {
            Node* del = temp->next;

            temp->next = del->next;

            if(del->next != NULL)
                del->next->prev = temp;

            delete del;

            return;
        }

        temp = temp->next;
    }

    cout<<"No node after 45\n";
}

// Display list
void display()
{
    Node* temp = head;

    cout<<"List: ";
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

    createList(n);

    display();

    addBeginning(90);
    display();

    addAfter45(100);
    display();

    deleteBeginning();
    display();

    deleteAfter45();
    display();
}
