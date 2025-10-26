#include <iostream>
using namespace std;

int count = 0;
class test
{
public:
    test()
    {
        count++;
        cout << "\nContructor message : object number : " << count << " created";
    }
    ~test()
    {
        cout << "\nDestructor message : object number : " << count << " destroyed";
        count--;
    }
};

int main()
{
    cout << "Inside the main block...";
    cout << "\nCreating first object t1...";
    test t1;
    {
        cout << "\nInside block1";
        cout << "\nCreating two more object t2 and t3";
        test t2, t3;
        cout << "\nLeaving block1";
    }
    cout << "\nBack inside the main block...";
    return 0;
}