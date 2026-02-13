  #include <iostream>
using namespace std;

int main()
{
    char *ptr;        
    ptr = new char;   

    cout << "Enter a character: ";
    cin >> *ptr;

    cout << "You entered: " << *ptr << endl;

    delete ptr;       
    ptr = NULL;       

    return 0;
}

