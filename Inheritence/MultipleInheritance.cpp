#include <iostream>
#include <string>
using namespace std;

class PersonalDetails
{
protected:
    string name;
    int age;

public:
    void inputPersonalDetails()
    {
        cout << "Enter name : ";
        getline(cin, name);
        cout << "Enter age : ";
        cin >> age;
        cin.ignore();
    }

    void displayPersonalDetails() const
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
    }
};

class AcedemicDetails
{
protected:
    string course;
    float grade;

public:
    void inputAcedemicDetails()
    {
        cout << "Enter course : ";
        getline(cin, course);
        cout << "Enter grade : ";
        cin >> grade;
    }

    void displayAcedemicDetails() const
    {
        cout << "Course : " << course << endl;
        cout << "Grade : " << grade << endl;
    }
};

class Student : public PersonalDetails, public AcedemicDetails
{
public:
    void inputDetails()
    {
        cout << "Enter student details :\n";
        inputPersonalDetails();
        inputAcedemicDetails();
    }

    void displayDetails() const
    {
        cout << "\n----Student information----\n";
        displayPersonalDetails();
        displayAcedemicDetails();
    }
};

int main()
{
    Student student;

    student.inputDetails();
    student.displayDetails();

    return 0;
}