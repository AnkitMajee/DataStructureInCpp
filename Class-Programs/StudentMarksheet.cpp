#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int rollNumber;
    int marks[5];
    int totalMarks;
    float percentage;

public:
    void inputDetails()
    {
        cout << "Enter student name : ";
        getline(cin, name);
        cout << "Enter roll number : ";
        cin >> rollNumber;
        cout << "Enter marks for 5 Subjects : \n";
        totalMarks = 0;
        for (int i = 0; i < 5; i++)
        {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
            totalMarks += marks[i];
        }
        percentage = (float)totalMarks / 5;
    }

    void displayMarksheet()
    {
        cout << "\n-----Marksheet-----\n";
        cout << "\nName : " << name << "\n";
        cout << "Roll number : " << rollNumber << "\n";
        cout << "\nMarks in subjects : \n";
        for (int i = 0; i < 5; i++)
        {
            cout << "Subject " << i + 1 << ": " << marks[i] << "\n";
        }
        cout << "\nTotal marks : " << totalMarks << "\n";
        cout << "Percentage : " << percentage << endl;
    }
};

int main()
{

    Student student;

    student.inputDetails();
    student.displayMarksheet();

    return 0;
}