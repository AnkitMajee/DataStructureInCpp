#include <iostream>
using namespace std;

class point
{
    int x, y;

public:
    point(int a, int b)
    {
        x = a;
        y = b;
    }
    void display()
    {
        cout << "x : " << x << " y : " << y;
    }
};

int main()
{
    point p1(1, 1);
    point p2(2, 2);
    cout << "Point p1 = ";
    p1.display();
    cout << "\nPoint p2 = ";
    p2.display();
    return 0;
}