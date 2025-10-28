#include <iostream>
using namespace std;

class B
{

    int a;

public:
    int b;
    void set_ab();
    int get_a();
    void show_a();
};

class D : public B
{
    int c;

public:
    void mul();
    void display();
};

void B::set_ab()
{
    a = 5;
    b = 10;
}

int B::get_a()
{
    return a;
}

void B::show_a()
{
    cout << "a : " << a << "\n";
}

void D::mul()
{
    c = b * get_a();
}

void D::display()
{
    cout << "a : " << get_a() << "\n";
    cout << "b : " << b << "\n";
    cout << "c : " << c << "\n";
}

int main()
{
    D obj;
    obj.set_ab();
    obj.mul();
    obj.show_a();
    obj.display();
    obj.b = 20;
    obj.mul();
    obj.display();
    return 0;
}