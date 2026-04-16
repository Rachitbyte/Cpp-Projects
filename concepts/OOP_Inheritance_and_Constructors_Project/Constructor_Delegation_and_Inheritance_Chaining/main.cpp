#include<iostream>
using namespace std;

class course{
	int courseid;
	string coursename;
	
public:
	course() : course(0, "Unavailable"){				//constructor delegation
		//cout << "course: Default constructor Invoked.\n";
	}
	
	course(int cid, string cname) : courseid(cid), coursename(cname){
		//cout << "course: Parameterized constructor Invoked.\n";
	}
	
	void displaycourse(){
		cout << "CourseId: " << courseid << "\tCourseName: " << coursename << endl;
	}
	
	~course(){
	//	cout << "course: Destructor called.\n";
	}
};

class student : public course{
	int studentid;
	string studentname;

public:
	student() : student(0, "Unknown", 0, "No Name"){		//constructor delegation
		//cout << "student: Default constructor Invoked.\n";
	}
	
	student(int cid, string cname, int sid, string sname) : course(cid, cname), studentid(sid), studentname(sname)
	{
		//cout << "student: Parametrized constructor Invoked.\n";
	}
	
	void displaystudent(){
		cout << "----------------------------- Student Display ----------------------------------\n\n";
		displaycourse();
		cout << "StudentId: " << studentid << "\tStudentName: " << studentname <<endl;
	}
	
	~student(){
	//	cout << "student: Destructor called.\n";
	}
};

int main()
{
	course c1, c2(1, "DBMS");
	c1.displaycourse();
	c2.displaycourse();
	student s1, s2(2, "Quantum Physics", 21, "Ashok Khan");
	s1.displaystudent();
	s2.displaystudent();			
	return 0;
}
