#include <iostream>
using namespace std;

class Student {
public:
    
    string name;
    int rollNumber;
    string course;
    int age;

    
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Course: " << course << endl;
        cout << "Age: " << age << endl;
        cout<<endl;
    }
};

int main() {
    
    Student student1, student2, student3;
    
    
    student1.name = "Raunak";
    student1.rollNumber = 101;
    student1.course = "Computer Science";
    student1.age = 20;
    
    
    student2.name = "Divyansh";
    student2.rollNumber = 102;
    student2.course = "Mechanical Engineering";
    student2.age = 21;
    
    
    student3.name = "Uday";
    student3.rollNumber = 103;
    student3.course = "Electrical Engineering";
    student3.age = 22;
    
    
    student1.displayDetails();
    student2.displayDetails();
    student3.displayDetails();

    return 0;
}
