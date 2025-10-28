#include <iostream>
using namespace std;

template <class T>
class test
{
    T a, b;

public:
    void getdata()
    {
        cin >> a >> b;
    }
    T sum()
    {
        return a + b;
    }
};

int main()
{
    test<int> t1;
    test<float> t2;
    cout << "Enter two integers : ";
    t1.getdata();
    cout << "Sum : " << t1.sum();
    cout << "\nEnter two floats : ";
    t2.getdata();
    cout << "Sum : " << t2.sum();
    return 0;
}