#include <iostream>
using namespace std;

// player structure
struct Player
{
    string name;
    int score;

    Player* next;
    Player* prev;
};

Player* head=NULL;

// insert player in sorted order
void addPlayer(string name,int score)
{
    Player* newNode=new Player();

    newNode->name=name;
    newNode->score=score;
    newNode->next=NULL;
    newNode->prev=NULL;

    // first node
    if(head==NULL)
    {
        head=newNode;
        return;
    }

    Player* temp=head;

    // insert at beginning
    if(score < head->score)
    {
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        return;
    }

    while(temp->next!=NULL && temp->next->score < score)
        temp=temp->next;

    newNode->next=temp->next;

    if(temp->next!=NULL)
        temp->next->prev=newNode;

    temp->next=newNode;
    newNode->prev=temp;
}

// delete player by name
void deletePlayer(string name)
{
    Player* temp=head;

    while(temp!=NULL)
    {
        if(temp->name==name)
        {
            if(temp->prev!=NULL)
                temp->prev->next=temp->next;
            else
                head=temp->next;

            if(temp->next!=NULL)
                temp->next->prev=temp->prev;

            delete temp;
            return;
        }

        temp=temp->next;
    }

    cout<<"Player not found\n";
}

// display whole list
void display()
{
    Player* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->name<<" - "<<temp->score<<endl;
        temp=temp->next;
    }
}

// lowest score player
void lowestScore()
{
    if(head!=NULL)
        cout<<"Lowest Score: "<<head->name<<" "<<head->score<<endl;
}

// display players with same score
void sameScore(int score)
{
    Player* temp=head;

    while(temp!=NULL)
    {
        if(temp->score==score)
            cout<<temp->name<<" "<<temp->score<<endl;

        temp=temp->next;
    }
}

// display backward from player
void backwardFromPlayer(string name)
{
    Player* temp=head;

    while(temp!=NULL)
    {
        if(temp->name==name)
        {
            while(temp!=NULL)
            {
                cout<<temp->name<<" "<<temp->score<<endl;
                temp=temp->prev;
            }
            return;
        }

        temp=temp->next;
    }

    cout<<"Player not found\n";
}

int main()
{
    addPlayer("Sadia",70);
    addPlayer("Aleena",65);
    addPlayer("Rida",70);
    addPlayer("Minha",60);

    cout<<"All Players\n";
    display();

    cout<<"\nLowest Score Player\n";
    lowestScore();

    cout<<"\nPlayers with score 70\n";
    sameScore(70);

    cout<<"\nBackward from Sara\n";
    backwardFromPlayer("Rida");

    deletePlayer("Aleena");

    cout<<"\nAfter Deletion\n";
    display();
}
