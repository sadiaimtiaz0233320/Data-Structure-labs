 #include <iostream>
using namespace std;

/*-------------------------------------------------------
        BOOK CLASS
  Yeh class book ki information store karegi
--------------------------------------------------------*/
class Book
{
public:

    string bookId;     // book ka ID
    string bookName;   // book ka name
    double bookPrice;  // book ki price
    string bookAuthor; // book ka author
    string bookISBN;   // book ka ISBN number

    // Default constructor
    Book()
    {
    }

    // Parameterized constructor
    Book(string id, string name, double price, string author, string isbn)
    {
        bookId = id;
        bookName = name;
        bookPrice = price;
        bookAuthor = author;
        bookISBN = isbn;
    }
};


/*-------------------------------------------------------
        NODE CLASS
  Har node ke andar ek book object aur
  next aur previous pointer hoga
--------------------------------------------------------*/
class Node
{
public:

    Book book;   // book object
    Node* next;  // next node ka pointer
    Node* prev;  // previous node ka pointer

    // constructor
    Node(Book b)
    {
        book = b;
        next = NULL;
        prev = NULL;
    }
};


/*-------------------------------------------------------
        BOOK LIST CLASS
  Yeh Doubly Circular Linked List banayegi
--------------------------------------------------------*/
class BookList
{
public:

    Node* head = NULL;   // list ka starting node


    /*----------------------------------------------
        ADD BOOK FUNCTION
        Naya book list me add karega
    ----------------------------------------------*/
    void addBook(string id,string name,double price,string author,string isbn)
    {

        // book object create
        Book b(id,name,price,author,isbn);

        // new node create
        Node* newNode = new Node(b);

        // agar list empty hai
        if(head == NULL)
        {
            head = newNode;

            // circular link
            head->next = head;
            head->prev = head;
        }

        else
        {
            // last node find
            Node* last = head->prev;

            // new node ko last ke baad lagao
            last->next = newNode;
            newNode->prev = last;

            // circular link maintain
            newNode->next = head;
            head->prev = newNode;
        }

        cout<<"Book added successfully\n";
    }



    /*----------------------------------------------
        REMOVE BOOK FUNCTION
        bookId ke through book delete karega
    ----------------------------------------------*/
    void removeBook(string id)
    {

        if(head == NULL)
        {
            cout<<"List empty\n";
            return;
        }

        Node* temp = head;

        do
        {
            if(temp->book.bookId == id)
            {

                // agar sirf ek node hai
                if(temp->next == head && temp->prev == head)
                {
                    head = NULL;
                }

                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;

                    if(temp == head)
                        head = temp->next;
                }

                cout<<"Book deleted successfully\n";
                return;
            }

            temp = temp->next;

        }while(temp != head);

        cout<<"Book not found\n";
    }



    /*----------------------------------------------
        UPDATE BOOK FUNCTION
        book ki information change karega
    ----------------------------------------------*/
    void updateBook(string id,string name,double price,string author,string isbn)
    {

        if(head == NULL)
        {
            cout<<"List empty\n";
            return;
        }

        Node* temp = head;

        do
        {
            if(temp->book.bookId == id)
            {

                temp->book.bookName = name;
                temp->book.bookPrice = price;
                temp->book.bookAuthor = author;
                temp->book.bookISBN = isbn;

                cout<<"Book updated successfully\n";
                return;
            }

            temp = temp->next;

        }while(temp != head);

        cout<<"Book not found\n";
    }



    /*----------------------------------------------
        PRINT ALL BOOKS
    ----------------------------------------------*/
    void printBooks()
    {

        if(head == NULL)
        {
            cout<<"List empty\n";
            return;
        }

        Node* temp = head;

        cout<<"\nBooks List\n";

        do
        {
            cout<<"Book ID: "<<temp->book.bookId<<endl;
            cout<<"Book Name: "<<temp->book.bookName<<endl;
            cout<<"Price: "<<temp->book.bookPrice<<endl;
            cout<<"Author: "<<temp->book.bookAuthor<<endl;
            cout<<"ISBN: "<<temp->book.bookISBN<<endl;

            cout<<"---------------------\n";

            temp = temp->next;

        }while(temp != head);
    }



    /*----------------------------------------------
        PRINT SINGLE BOOK
    ----------------------------------------------*/
    void printBook(string id)
    {

        Node* temp = head;

        do
        {
            if(temp->book.bookId == id)
            {

                cout<<"Book Found\n";

                cout<<"Book ID: "<<temp->book.bookId<<endl;
                cout<<"Name: "<<temp->book.bookName<<endl;
                cout<<"Price: "<<temp->book.bookPrice<<endl;
                cout<<"Author: "<<temp->book.bookAuthor<<endl;
                cout<<"ISBN: "<<temp->book.bookISBN<<endl;

                return;
            }

            temp = temp->next;

        }while(temp != head);

        cout<<"Book not found\n";
    }

};



/*-------------------------------------------------------
                MAIN FUNCTION
--------------------------------------------------------*/
int main()
{

    BookList list;

    // assignment ke mutabiq addBook ko 10 times call karna hai

    list.addBook("1","C++",500,"Sadia","111");
    list.addBook("2","Java",600,"Rida","222");
    list.addBook("3","Python",700,"Aleena","333");
    list.addBook("4","DSA",800,"Hina","444");
    list.addBook("5","DBMS",550,"Mihahil","555");
    list.addBook("6","AI",650,"Laiba","666");
    list.addBook("7","ML",750,"Fatima","777");
    list.addBook("8","OS",450,"Ali","888");
    list.addBook("9","Networks",900,"Ayesha","999");
    list.addBook("10","OOP",500,"Khan","000");


    // saari books print karna
    list.printBooks();


    // single book print
    list.printBook("3");


    // book update
    list.updateBook("3","Advanced Python",750,"Ahmed","333");


    // book delete
    list.removeBook("5");


    // dubara print
    list.printBooks();

}
