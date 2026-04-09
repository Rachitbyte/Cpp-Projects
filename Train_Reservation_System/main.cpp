#include <bits/stdc++.h>
using namespace std;

struct train 
{
    int tno;
    int tseats;
    int bseats;
    string ttype;
    string departure;
    string destination;
    
} t[10] = {
    {101, 20, 0, "mail", "Old Mumbai", "Borivali"},
    {102, 25, 0, "express", "Kolkata", "Bengaluru"},
    {103, 30, 0, "mail", "Mira Road", "Wankhede"},
    {104, 35, 0, "express", "Agra", "Patna"},
    {105, 15, 0, "mail", "Maninagar", "Kubernagar"}
};
int size = 5;

struct booking
{
	int tno;
	string pname;
	int bseats;	
	
} b[50]={
	{101, "vikram thakur", 4},
	{102, "naruto sharma", 14},
	{104, "sunil patel", 10},
	{101, "sohail khan", 12}
};
int bookingsize = 4;


void menu();					// function declaration for mainmenu
void adminlogin();				// function declaration
void guestmenu();				// function declaration for guestpage menu
void adminmenu();				// function declaration for adminpage mainmenu
void traindetails();			// function declaration for displaying train details in admin
void trainbooking();			// function declaration for showing train booking by guest
void availabletrains();			// function declaration for showing available trains in guest
void viewbooking();				// function declaration for viewing bookings by guest
void addtrain();				// function declaration for adding trains by admin
void reports();					// function declaration for viewing reports by admin
void searchbytype();			// function declaration for searching trains by type
void searchbydeparture();		// function declaration for searching trains by departure station
void searchbydestination();		// function declaration for searching trains by arrival station
void searchbookedseats();		// function declaration for searching bookedseats by train number

void menu() 	// menu() function definition
{
	start:		//used as goto variable for invalid choice..!
    system("cls");		int choice;
    cout << "****************************************************\n";
    cout << "		   TRAIN PORTAL\n";
    cout << "****************************************************\n";
    cout << "0.\tExit\n"
    	 <<	"1.\tAdmin Login\n"
    	 << "2.\tGuest Menu\n";
    cout << "Enter Your Choice to continue: ";
    cin  >> choice;
	
	switch(choice)
	{
		case 0:
			cout << "Exit Action Completed...";		break;
			
		case 1:
			adminlogin();
			break;
			
		case 2:
			guestmenu();
			break;
			
		default:
			cout << "Invalid Selection...";	getch();	goto start;
	}
}

void adminlogin() 	// adminlogin() function definition
{
    
	start:			// goto variable used for invalid credentials ??
    system("cls");   string username, password;
    cout << "************************************************\n";
    cout << "          ADMIN SIGN IN REQUIRED\n";
    cout << "************************************************\n";
    cout << "Enter Username: ";
    cin  >> username;
    cout << "Enter Password: ";
    cin  >> password;

    if (username == "admin" && password == "admin") 
	{
        system("cls");
        cout << "LOGIN SUCCESSFUL...\n";
        cout << "Enter to Continue... ";
        getch();
        adminmenu();
    }
	 else 
	 {
        char response;
        cout << "Invalid Login Credentials.\n";
        cout << "Would like to Try \"LOGIN\" Again [y/n]? ";
        cin >> response;
        if (response == 'y')    goto start;   // this redirects to login for fresh creds...
        else    menu(); 	// redirects to menu...
        
    }
}

void adminmenu() {
    system("cls");	int choice;
    cout << "************************************************\n";
    cout << "          ADMIN MAIN MENU\n";
    cout << "************************************************\n";
    cout << "0. Logout\n";
    cout << "1. Train Details\n";
    cout << "2. Add Train\n";
    cout << "3. Reports\n\n";
    cout << "Enter Your Choice: ";
    cin >> choice;

    switch (choice) 
	{
        case 0:
       		cout << "Log Out From System Completed...\nEnter To Continue...";	 
			getch();	menu();
            break;
            
        case 1:
           	traindetails();
            break;
            
        case 2:
        	addtrain();
        	break;
        	
        case 3:
        	reports();
        	break;
    }
}

void traindetails() 	// traindetails() function definition
{
	system("cls");
    
    	cout << left << setw(18) << "Train Number"
		     << left << setw(12) << "Type"
    		 << left << setw(15) << "Departure"
			 << left << setw(15) << "destination"
			 << left << setw(5)  << "Seats\n";
		cout << "----------------------------------"
			 << "----------------------------------\n";

	for(int i = 0; i < size; i++)
	{
		cout << left << setw(18) << t[i].tno
		     << left << setw(12) << t[i].ttype
    		 << left << setw(15) << t[i].departure
			 << left << setw(15) << t[i].destination
			 << left << setw(8)  << t[i].tseats << endl << endl;
	}
	cout << "Enter to Redirect Admin Menu...";	getch();	adminmenu();
}

void addtrain()
{
	system("cls");
	cout << "********** ADD TRAIN **********\n";
	cout << "Enter train number: ";
	cin  >> t[size].tno;
	cout << "Enter Train Type: ";
	cin  >> t[size].ttype;
	cout << "Enter Departure: ";	fflush(stdin);
	getline(cin, t[size].departure);
	cout <<  "Enter destination: ";		fflush(stdin);
	getline(cin, t[size].destination);
	cout << "Enter Total Seats: ";
	cin  >> t[size].tseats;
	t[size].bseats = 0;
	size++;
	cout << "Enter to Redirect Admin Menu...";	getch();	adminmenu();
}

void reports()
{
	system("cls");	int choice;
	cout << "****************** Train Reports ******************\n\n";
	cout << "0.\tExit\n"
		 << "1.\tSearch Trains by Type\n"
		 << "2.\tSearch Trains by Departure Station\n"
		 << "3.\tSearch Trains by Destination Station\n"
		 << "4.\tSearch Booked Seats by Train Number\n";
	cout << "Enter Your Choice to Continue: ";
	cin  >> choice;
	switch(choice)
	{
		case 0:
			cout << "Enter To Continue to Admin Menu...";	getch();
			adminmenu();
			break;
			
		case 1:
			searchbytype();			
			break;
			
		case 2:
			searchbydeparture();
			break;
			
		case 3:
			searchbydestination();
			break;
			
		case 4:
			searchbookedseats();
			break;
	}
}

void searchbytype()
{
	system("cls");	string type;
			cout << "Enter train type to find trains: ";
			cin  >> type;
			if(type == "express")
			{
				for(int i=0; i<size; i++)
				{
					if(t[i].ttype == "express")
					{
						cout << "Train number : " << t[i].tno << endl;	
					}
				}
				cout << "Enter to Redirect Back...";	getch();	reports();
			}
			else if(type == "mail")
			{
				for(int i=0; i<size; i++)
				{
					if(t[i].ttype == "mail")
					{
						cout << "Train number : " << t[i].tno << endl;
					}
				}
				cout << "Enter to Redirect Back...";	getch();	reports();
			}
			else
			{
				cout << "Invalid Spelling [express & mail]...";
				cout << "Enter to Continue...";		getch();	reports();
			}
}

void searchbydeparture()
{
	system("cls");	string station;	int count=0;
	cout << "Enter Departure Station: ";	fflush(stdin);
	getline(cin,station);
	for(int i=0; i<size; i++)
	{
		if(station == t[i].departure)
		{
			cout <<  "Train Number : " << t[i].tno << endl;	count++;
		}
	}
	if(count == 0)
	{
		cout << "NO TRAIN HAS SUCH DEPARTURE STATION...\n";
	}
	cout << "Press Enter to Redirect..";	getch();	reports();
}

void searchbydestination()
{
	system("cls");	string station;	int count=0;
	cout << "Enter Destination Station: ";	fflush(stdin);
	getline(cin,station);
	for(int i=0; i<size; i++)
	{
		if(station == t[i].destination)
		{
			cout <<  "Train Number : " << t[i].tno << endl;	count++;
		}
	}
	if(count == 0)
	{
		cout << "NO TRAIN HAS SUCH DESTINATION STATION...\n";
	}
	cout << "Press Enter to Redirect..";	getch();	reports();
}

void searchbookedseats()
{
	system("cls");		int trainnumber, count=0;
	cout << "Enter Train Number to search booked Seats: ";
	cin  >> trainnumber;
	
	for(int i=0; i<size; i++)
	{
		if(trainnumber == t[i].tno)
		{
			cout << "Total Seats: " << t[i].tseats << endl;
			cout << "Booked Seats: " << t[i].bseats << endl;
			cout << "Enter to Redirect menu...";	getch();	reports();
		}
	}
	if(count == 0)
	{
		cout << "NO SUCH TRAIN AVAILABLE...\n";
		cout << "Enter to Redirect menu...";	getch();	reports();
	}
}

void guestmenu()     // guestmenu() function definition
{
	start:
	system("cls");	int choice;
    cout << "************************************************\n";
    cout << "          GUEST MAIN MENU\n";
    cout << "************************************************\n";
    cout << "0.\tBack To Menu\n";
    cout << "1.\tTrain Booking\n";
    cout <<	"2.\tView Bookings\n";
    cout << "Enter Your Choice To Continue: ";
    cin  >> choice;
    
    switch(choice)
    {
    	case 0:
    		cout << "Log Out From System Completed...\nEnter To Continue...";	 
			getch();	menu();
            break;
            
        case 1:
           	trainbooking();
            break;
    	
		case 2:
			viewbooking();
			break;
		
		default:
			cout << "Invalid Choice... Enter to continue...";	getch();	
			goto start;	
    		
	}
}

void availabletrains()
{
		system("cls");
	cout << "********** Avilable Trains **********\n";
		cout << left << setw(18) << "Train Number"
		     << left << setw(12) << "Type"
    		 << left << setw(15) << "Departure"
			 << left << setw(15) << "destination"
			 << left << setw(5)  << "Available Seats\n";
		cout << "----------------------------------"
			 << "----------------------------------\n";	
	
	for(int i = 0; i < size; i++)
	{
		if(t[i].tseats-t[i].bseats > 0)
		{
			cout << left << setw(18) << t[i].tno
			     << left << setw(12) << t[i].ttype
    			 << left << setw(15) << t[i].departure
				 << left << setw(15) << t[i].destination
				 << left << setw(8)  << t[i].tseats-t[i].bseats << endl << endl;
		}
	}
	
}

void trainbooking()
{
	availabletrains();
	
	cout << "Enter Your Name: ";	fflush(stdin);
	getline(cin,b[bookingsize].pname);
	cout << "Enter Train Number: ";
	cin  >> b[bookingsize].tno;
	retry:	//it is for booking seats lees than 0 or more than exists...
	cout << "Enter Seats Quantity: ";
	cin  >> b[bookingsize].bseats;
	
	
	for(int i=0; i<size ;i++)
	{
		if(b[bookingsize].tno == t[i].tno)
		{
			if(b[bookingsize].bseats > t[i].tseats-t[i].bseats || b[bookingsize].bseats < 1)
			{
				cout << "Enter Seats Again By Checking Available Seats...\n";
				goto retry;
			}
			t[i].bseats = b[bookingsize].bseats;
		}
	}
	cout << "Train Booked Successfully...\n";
	bookingsize++;
	cout << "Enter to Redirect Guest Menu: ";	getch();	guestmenu();
}

void viewbooking()
{
	system("cls");
    
    	cout << left << setw(20) << "Passenger Name"
		     << left << setw(12) << "Train No."
			 << left << setw(12) << "Booked Seats\n";
		cout << "------------------------------------------------------\n";

	for(int i = 0; i < bookingsize; i++)
	{
		cout << left << setw(22) << b[i].pname
		     << left << setw(12) << b[i].tno
			 << left << setw(8)  << b[i].bseats << endl << endl;
	}
	cout << "Enter to Redirect Guest Menu...";	getch();	guestmenu();
}

int main() 
{
    menu();
    return 0;
}
