#include <iostream>
using namespace std;

struct Node
{
    int rain;
    Node* next;
    Node* prev;
};

Node* head=NULL;

// insert rainfall data
void insert(int value)
{
    Node* newNode = new Node();
    newNode->rain = value;
    newNode->next=NULL;
    newNode->prev=NULL;

    if(head==NULL)
    {
        head=newNode;
        return;
    }

    Node* temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;
    newNode->prev=temp;
}

void rainfallStats()
{
    Node* temp=head;

    int total=0;
    int highest=-1;
    int lowest=9999;
    int day=1,highDay=1,lowDay=1;

    while(temp!=NULL)
    {
        total+=temp->rain;

        if(temp->rain>highest)
        {
            highest=temp->rain;
            highDay=day;
        }

        if(temp->rain<lowest)
        {
            lowest=temp->rain;
            lowDay=day;
        }

        temp=temp->next;
        day++;
    }

    cout<<"Total Rainfall: "<<total<<endl;
    cout<<"Average Rainfall: "<<total/7.0<<endl;
    cout<<"Highest Rainfall Day: "<<highDay<<endl;
    cout<<"Lowest Rainfall Day: "<<lowDay<<endl;
}

// rainfall after 5th node
void rainfallAfter5th()
{
    Node* temp=head;

    for(int i=1;i<6;i++)
    {
        if(temp==NULL)
        return;

        temp=temp->next;
    }

    if(temp!=NULL)
        cout<<"Rainfall after 5th node: "<<temp->rain<<endl;
    else
        cout<<"No node after 5th\n";
}

int main()
{
    int rain;

    for(int i=1;i<=7;i++)
    {
        do
        {
            cout<<"Enter rainfall for day "<<i<<": ";
            cin>>rain;

        }while(rain<0); // input validation

        insert(rain);
    }

    rainfallStats();

    rainfallAfter5th();
}
