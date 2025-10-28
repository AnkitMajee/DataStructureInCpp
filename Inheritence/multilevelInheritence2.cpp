#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    void setPersonDetails()
    {
        cout << "Enter name : ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter age : ";
        cin >> age;
    }

    void displayPersonDetails() const
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
    }
};

class Student : public Person
{
protected:
    string course;
    int rollNum;

public:
    void setStudentDetails()
    {
        setPersonDetails();

        cout << "Enter roll number : ";
        cin >> rollNum;
        cin.ignore();
        cout << "Enter course : ";
        getline(cin, course);
    }

    void displayStudentDetails() const
    {
        displayPersonDetails();

        cout << "Roll number : " << rollNum << endl;
        cout << "Course : " << course << endl;
    }
};

class Employee : public Person
{
protected:
    string jobTitle;
    double salary;

public:
    void setEmployeeDetails()
    {
        setPersonDetails();

        cout << "Enter job title : ";
        cin.ignore();
        getline(cin, jobTitle);
        cout << "Enter salary : ";
        cin >> salary;
    }

    void displayEmployeeDetails() const
    {
        displayPersonDetails();

        cout << "Job title : " << jobTitle << endl;
        cout << "Salary : " << salary << endl;
    }
};

int main()
{
    int choice;

    cout << "Choose an option :\n1. Student details\n2. Employee details\n";
    cin >> choice;

    if (choice == 1)
    {
        Student student;

        cout << "Enter student details : \n";
        student.setStudentDetails();
        cout << "\nStudent details : \n";
        student.displayStudentDetails();
    }
    else if (choice == 2)
    {
        Employee employee;

        cout << "Enter employee details : \n";
        employee.setEmployeeDetails();
        cout << "\nEmployee details : \n";
        employee.displayEmployeeDetails();
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}