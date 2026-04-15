#include<iostream>
#include<cstdlib>
using namespace std;

class Student{
	string name;
	int rollno;
	
	public:
		void input_student(){
			cout << "--------------- Input Student ---------------\n\n";
			cout << "Enter Student Name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter Student Rollno: ";
			cin  >> rollno;
		}
		void display_student(){
			cout << "Student Name:" << name << endl;
			cout << "\tStudent Rollno: " << rollno << endl << endl;
		}
		int get_rollno(){
			return rollno;	
		}
};

class Exam_info{
	protected:
		string subject_name;
		int total_marks;
	
	public:
		void input_exam_info(){
			cout << "--------------- Input Exam Info ---------------\n\n";
			cout << "Enter Subject Name: ";
			cin.ignore();
			getline(cin, subject_name);
			cout << "Enter Total Marks: ";
			cin  >> total_marks;
		}
		void display_exam_info(){
			cout << "Subject Name: " << subject_name << endl;
			cout << "\tTotal Marks: " << total_marks << endl;
		}
};

class Exam : protected Exam_info{
	private:
		int obtained_marks;
	
	public:
		void input_exam(){
			input_exam_info();
			cout << "--------------- Input Exam ---------------\n\n";
			cout << "Enter Obtained Marks: ";
			cin  >> obtained_marks;	
		}
		void display_exam(){
			display_exam_info();
			cout << "\tObtained Marks: " << obtained_marks;
		}
};

class College{
	
	int student_count;
	int exam_count;
	Student* s;
	Exam*  e;
	
	public:
		College(Student* std, Exam* exm)
		{		//CONSTRUCTOR
			cout << "Class(College): Default Constructor Called!\n\n";
			student_count = -1;
			exam_count = -1;
			s=std;	e=exm;
		}
		void add_student(){
			if(student_count >= 10){
			cout << "Student Limit Exceeded";
			return;
			}
			s[++student_count].input_student();
			cout << "Student Added!";
			cin.ignore();
			cin.get();
		}
		void view_student(){
			cout << "--------------- View All Student ---------------\n\n";
			for(int i=0; i<=student_count; i++){
				cout << i+1 << "\t";
				s[i].display_student();
			}
			cin.ignore();
			cin.get();
		}
		void remove_student(){
			int rollnum, count=0;
			cout << "--------------- View All Student ---------------\n\n";
			for(int i=0; i<=student_count; i++){
				cout << i+1 << "\t";
				s[i].display_student();
			}
			cout << "Enter a RollNo to Remove from Records...\n";
			cout << "Rollno: ";
			cin  >> rollnum;
			for(int i=0; i<=student_count; i++){
				if(rollnum == s[i].get_rollno()){
					for(int j=i;j<student_count;j++){
						s[j]=s[j+1];
					}
					count++;
					student_count--;
					cout << "Student Record has been removed.";
					return;
				}
			}
			if(count != 1)	cout << "No Student Found!";
			cin.ignore();	cin.get();	return;
		}
		void add_exam(){
			if(exam_count >= 10){
			cout << "Exam Limit Exceeded";
			return;
			}
			e[++exam_count].input_exam();
			cout << "Exam Added!";
			cin.ignore();
			cin.get();
		}
		void view_exam(){
			cout << "--------------- View All Exam Info ---------------\n\n";
			for(int i=0; i<=exam_count; i++){
				cout << i+1 << "\t";
				e[i].display_exam();
			}
			cin.ignore();
			cin.get();
		}
};

int main()
{
	Student s[10];
	Exam e[10];
	College c(s, e);
	int choice;

    do {
    	system("cls");
        cout << "\n================ MENU ================\n";
        cout << "1. Add Student\n"
				"2. View Students\n"
		        "3. Add Exam\n"
				"4. View Exams\n"
				"5. Remove Student from Record\n"
				"6. Exit\n";
	    cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice){
        	case 1:
        		c.add_student();
        		break;
        	case 2:
        		c.view_student();
        		break;
        	case 3:
        		c.add_exam();
        		break;
        	case 4:
        		c.view_exam();
        		break;
        	case 5:
        		c.remove_student();
        		break;
        	case 6:
        		break;
        	default:
        		cout << "Invalid Choice!";
		}
        
    }while(choice != 6);
	return 0;
}
