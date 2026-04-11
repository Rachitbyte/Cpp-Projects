#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// ---------------- BASE CLASS ----------------
class Person {
protected:
    char name[50];
    int age;

public:
    void input_person() {
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 50);

        cout << "Enter Age: ";
        cin >> age;
    }

    void display_person() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

// ---------------- SINGLE INHERITANCE ----------------
class Student : public Person {
protected:
    int id;
    char course[50];
    int marks;

public:
    void input() {
        cout << "Enter ID: ";
        cin >> id;
        input_person();

        cout << "Enter Course: ";
        cin.ignore();
        cin.getline(course, 50);

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "\n--- Student ---\n";
        cout << "ID: " << id << endl;
        display_person();
        cout << "Course: " << course << "\nMarks: " << marks << endl;
    }

    int getID() { return id; }
};

// ---------------- MULTILEVEL INHERITANCE ----------------
class ClassMonitor : public Student {
    char responsibility[50];

public:
    void input_monitor() {
        input();
        cout << "Enter Responsibility: ";
        cin.ignore();
        cin.getline(responsibility, 50);
    }

    void display_monitor() {
        display();
        cout << "Responsibility: " << responsibility << endl;
    }
};

// ---------------- HIERARCHICAL INHERITANCE ----------------
class Teacher : public Person {
    char subject[50];

public:
    void input_teacher() {
        input_person();
        cout << "Enter Subject: ";
        cin.ignore();
        cin.getline(subject, 50);
    }

    void display_teacher() {
        cout << "\n--- Teacher ---\n";
        display_person();
        cout << "Subject: " << subject << endl;
    }
};

class Staff : public Person {
    char department[50];

public:
    void input_staff() {
        input_person();
        cout << "Enter Department: ";
        cin.ignore();
        cin.getline(department, 50);
    }

    void display_staff() {
        cout << "\n--- Staff ---\n";
        display_person();
        cout << "Department: " << department << endl;
    }
};

// ---------------- MULTIPLE INHERITANCE ----------------
class Exam {
protected:
    int exam_marks;

public:
    void input_exam() {
        cout << "Enter Exam Marks: ";
        cin >> exam_marks;
    }
};

class Sports {
protected:
    int sports_marks;

public:
    void input_sports() {
        cout << "Enter Sports Marks: ";
        cin >> sports_marks;
    }
};

class Result : public Exam, public Sports {
public:
    void display_result() {
        cout << "Total Marks: " << (exam_marks + sports_marks) << endl;
    }
};

// ---------------- FILE FUNCTIONS (STUDENT ONLY) ----------------
void addStudent() {
    Student s;
    ofstream file("school.dat", ios::binary | ios::app);

    s.input();
    file.write((char*)&s, sizeof(s));

    file.close();
    cout << "Added.\n";
}

void viewStudents() {
    Student s;
    ifstream file("school.dat", ios::binary);

    while (file.read((char*)&s, sizeof(s))) {
        s.display();
    }

    file.close();
}

void searchStudent() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    Student s;
    ifstream file("school.dat", ios::binary);

    bool found = false;
    while (file.read((char*)&s, sizeof(s))) {
        if (s.getID() == id) {
            s.display();
            found = true;
            break;
        }
    }

    if (!found) cout << "Not found\n";
    file.close();
}

// ---------------- MAIN MENU ----------------
int main() {
    int choice;

    do {
        cout << "\n===== SCHOOL SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Demonstrate Inheritance\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {

        case 1: addStudent(); break;
        case 2: viewStudents(); break;
        case 3: searchStudent(); break;

        case 4: {
            cout << "\n--- Demonstrating Inheritance ---\n";

            ClassMonitor m;
            m.input_monitor();
            m.display_monitor();

            Teacher t;
            t.input_teacher();
            t.display_teacher();

            Staff s;
            s.input_staff();
            s.display_staff();

            Result r;
            r.input_exam();
            r.input_sports();
            r.display_result();

            break;
        }

        case 5: cout << "Exit\n"; break;
        default: cout << "Invalid\n";
        }

    } while (choice != 5);

    return 0;
}
