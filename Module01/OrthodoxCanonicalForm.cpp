// CPP Program to demonstrate the use of copy constructor
// and assignment operator
#include <iostream>
#include <stdio.h>
using namespace std;
 
class Test {
public:
    Test() {cout << "Default Constructor called " << endl;};
    ~Test() {cout << "Distructor called " << endl;};
    Test(const Test& t)
    {
        cout << "Copy constructor called " << endl;
    };
 
    Test& operator=(const Test& t)
    {
        cout << "Assignment operator called " << endl;
        return *this;
    };
};
 
// Driver code
int main()
{
    Test t1, t2;
    t2 = t1;
    Test t3 = t1;
    Test t4(t1);
    return 0;
}