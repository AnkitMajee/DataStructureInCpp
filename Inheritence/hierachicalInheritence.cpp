#include <iostream>
using namespace std;

class Number
{
protected:
    int num;

public:
    void setNumber(int n)
    {
        num = n;
    }
};

class Square : public Number
{
public:
    int getSquare()
    {
        return num * num;
    }
};

class Cube : public Number
{
public:
    int getCube()
    {
        return num * num * num;
    }
};

int main()
{
    int n;

    cout << "Enter number : ";
    cin >> n;

    Square obj1;
    obj1.setNumber(n);

    cout << "Square of " << n << " is : " << obj1.getSquare() << endl;

    Cube obj2;
    obj2.setNumber(n);

    cout << "Cube of " << n << " is : " << obj2.getCube() << endl;

    return 0;
}