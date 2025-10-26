#include <iostream>
using namespace std;

class item
{
public:
    int number;
    float cost;
    void getdata(int a, float b);
    void putdata()
    {
        cout << "Number : " << number << "\n";
        cout << "Cost : " << cost << "\n";
    }
};

void item::getdata(int a, float b)
{
    number = a;
    cost = b;
}

int main()
{
    item x;
    cout << "\nObject x" << "\n";
    x.getdata(100, 29.5);
    x.putdata();

    item y;
    cout << "\nObject y" << "\n";
    y.getdata(200, 75.5);
    y.putdata();
    return 0;
}