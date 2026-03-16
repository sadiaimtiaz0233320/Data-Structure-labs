#include <iostream>
using namespace std;

/*------------------------------------------
        BOOK CLASS
-------------------------------------------*/
class Book
{
public:
    string title;
    double price;
    int edition;
    int pages;

    // constructor
    Book(string t,double p,int e,int pg)
    {
        title = t;
        price = p;
        edition = e;
        pages = pg;
    }
};


/*------------------------------------------
        NODE CLASS
-------------------------------------------*/
class Node
{
public:

    Book book;      // book object
    Node* next;     // pointer to next node

    Node(Book b) : book(b)
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

    Node* top = NULL;   // stack ka top pointer


    // PUSH FUNCTION
    void push(string title,double price,int edition,int pages)
    {
        Book b(title,price,edition,pages);

        Node* newNode = new Node(b);

        newNode->next = top;
        top = newNode;

        cout<<"Book pushed into stack\n";
    }


    // POP FUNCTION
    void pop()
    {
        if(top == NULL)
        {
            cout<<"Stack empty\n";
            return;
        }

        Node* temp = top;
        top = top->next;

        cout<<"Book popped\n";

        delete temp;
    }


    // PEEK FUNCTION
    void peek()
    {
        if(top == NULL)
        {
            cout<<"Stack empty\n";
            return;
        }

        cout<<"\nTop Book\n";

        cout<<"Title: "<<top->book.title<<endl;
        cout<<"Price: "<<top->book.price<<endl;
        cout<<"Edition: "<<top->book.edition<<endl;
        cout<<"Pages: "<<top->book.pages<<endl;
    }


    // DISPLAY FUNCTION
    void display()
    {
        Node* temp = top;

        cout<<"\nRemaining Books\n";

        while(temp != NULL)
        {
            cout<<"Title: "<<temp->book.title<<endl;
            cout<<"Price: "<<temp->book.price<<endl;
            cout<<"Edition: "<<temp->book.edition<<endl;
            cout<<"Pages: "<<temp->book.pages<<endl;

            cout<<"----------------\n";

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

    // push 5 books
    s.push("C++",500,3,400);
    s.push("Java",600,2,450);
    s.push("Python",700,4,500);
    s.push("DSA",800,1,350);
    s.push("OS",750,2,600);

    // find top element
    s.peek();

    // pop 2 books
    s.pop();
    s.pop();

    // display remaining books
    s.display();

}
