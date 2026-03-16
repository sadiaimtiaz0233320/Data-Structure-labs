#include <iostream>
using namespace std;

/*------------------------------------------
        INVENTORY CLASS
-------------------------------------------*/
class Inventory
{
public:

    int serialNum;
    int manufactYear;
    int lotNum;

    Inventory(int s,int y,int l)
    {
        serialNum = s;
        manufactYear = y;
        lotNum = l;
    }
};


/*------------------------------------------
        NODE CLASS
-------------------------------------------*/
class Node
{
public:

    Inventory item;
    Node* next;

    Node(Inventory i) : item(i)
    {
        next = NULL;
    }
};


/*------------------------------------------
        STACK CLASS
-------------------------------------------*/
class Stack
{
public:

    Node* top = NULL;


    // PUSH PART
    void push(int serial,int year,int lot)
    {
        Inventory i(serial,year,lot);

        Node* newNode = new Node(i);

        newNode->next = top;
        top = newNode;

        cout<<"Part added to inventory\n";
    }


    // POP PART
    void pop()
    {
        if(top == NULL)
        {
            cout<<"Inventory empty\n";
            return;
        }

        Node* temp = top;

        cout<<"\nRemoved Part\n";

        cout<<"Serial: "<<temp->item.serialNum<<endl;
        cout<<"Year: "<<temp->item.manufactYear<<endl;
        cout<<"Lot: "<<temp->item.lotNum<<endl;

        top = top->next;

        delete temp;
    }


    // DISPLAY ALL
    void display()
    {
        Node* temp = top;

        cout<<"\nRemaining Inventory\n";

        while(temp != NULL)
        {
            cout<<"Serial: "<<temp->item.serialNum<<endl;
            cout<<"Year: "<<temp->item.manufactYear<<endl;
            cout<<"Lot: "<<temp->item.lotNum<<endl;

            cout<<"--------------\n";

            temp = temp->next;
        }
    }

};


/*------------------------------------------
        MAIN FUNCTION
-------------------------------------------*/
int main()
{

    Stack s;

    int choice;

    do
    {
        cout<<"\n1 Add Part\n";
        cout<<"2 Remove Part\n";
        cout<<"3 Exit\n";

        cin>>choice;

        if(choice == 1)
        {
            int serial,year,lot;

            cout<<"Enter Serial Number: ";
            cin>>serial;

            cout<<"Enter Manufacture Year: ";
            cin>>year;

            cout<<"Enter Lot Number: ";
            cin>>lot;

            s.push(serial,year,lot);
        }

        else if(choice == 2)
        {
            s.pop();
        }

    }while(choice != 3);

    // show remaining items
    s.display();

}
