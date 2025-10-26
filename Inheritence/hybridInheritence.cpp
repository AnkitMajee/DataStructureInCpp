#include <iostream>
using namespace std;

class student
{

protected:
    int roll_no;

public:
    void get_number(int a);
    void put_number();
};

void student::get_number(int a)
{
    roll_no = a;
}

void student::put_number()
{
    cout << "Roll number : " << roll_no << "\n";
}

class test : public student
{
protected:
    float sub1, sub2;

public:
    void get_marks(float x, float y);
    void put_marks();
};

void test::get_marks(float x, float y)
{
    sub1 = x;
    sub2 = y;
}

void test::put_marks()
{
    cout << "Marks of sub1 : " << sub1 << "\n";
    cout << "Marks of sub2 : " << sub2 << "\n";
}

class sports
{
protected:
    float score;

public:
    void get_score(float s);
    void put_score();
};

void sports::get_score(float s)
{
    score = s;
}

void sports::put_score()
{
    cout << "Score : " << score << "\n";
}

class result : public test, public sports
{
    float total;

public:
    void display()
    {
        total = sub1 + sub2 + score;
        put_number();
        put_marks();
        put_score();
        cout << "Total : " << total;
    }
};

int main()
{
    result student1;
    student1.get_number(100);
    student1.get_marks(89, 94);
    student1.get_score(8.5);
    student1.display();
    return 0;
}