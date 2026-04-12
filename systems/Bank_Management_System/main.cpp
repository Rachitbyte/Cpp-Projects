#include<bits/stdc++.h>
using namespace std;

// function declaration
void login_page();
void admin_login();
void admin_mainmenu();
void user_signup();
void user_login();
void user_mainmenu(int);
void new_acc();
void deposit_in_acc(int);	//for user
void deposit_in_acc();		//for admin
void withdraw_from_acc();	//for admin
void withdraw_from_acc(int);//for user
void view_all_acc();
void check_balance(int);	//for user
void check_balance();		//for admin
void update_name();
void update_name(int);		//for user
void view_acc_details(int);	//for user

class Account{
	int acc_num;
	char name[50];
	float balance;
	char acc_type[8];
	char pass[50];
	
	public:
		static int count;
		int get_acc_num(){
			return acc_num;
		}
		float get_balance(){
			return balance;
		}
		string get_pass(){
			return pass;
		}
		void new_acc(int acc_num){
			
			this->acc_num = acc_num;
			cout << "Enter Account password: ";
			cin  >> pass;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ENTER HOLDER NAME: ";
			cin.getline(name, sizeof(name));
			
			top:
			cout << "ENTER FIRST DEPOSIT: ";
			cin  >> balance;
			if(balance < 1){
				cout << "DEPOSIT AMOUNT SHOULD BE ATLEAST 1 Rupee.\n";
				system("pause");
				goto top;
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			int choice=0;
			do{
				cout << "ENTER ACCOUNT TYPE(SAVINGS/CURRENT): ";
				cout << "\n1. Savings\n"
					 << "2. Current\n";
				cin  >> choice;
				switch (choice){
					case 1:
						strncpy(acc_type, "Savings", sizeof(acc_type));
						acc_type[sizeof(acc_type) - 1] = '\0';
						cout << "Account Type: Savings\n";
						break;
						
					case 2:
						strncpy(acc_type, "Current", sizeof(acc_type));
						acc_type[sizeof(acc_type) - 1] = '\0';
						cout << "Account Type: Current\n";
						break;
					
					default:
						cout << "\nInvalid Choice !\n";
				}
			}while(choice != 1 && choice != 2);
			cout  << "\nAccount Created Successfully !\n";
		}
		
		void deposit_in_acc(float deposit_amount){
			balance += deposit_amount;
		}
		
		void withdraw_from_acc(float withdraw_amount){
			balance -= withdraw_amount;
		}
		
		void display_details(){
			count++;
			if(count == 1){
				cout << endl << setw(20) << "Account Number";
				cout << setw(20) << "Holder Name";
				cout << setw(20) << "Account Balance";
				cout << setw(20) << "Account Type";
				cout << setw(20) << "Password" << endl;
			}
			cout << endl << setw(20) << acc_num;
			cout << setw(20) << name;
			cout << setw(20) << balance;
			cout << setw(20) << acc_type;
			cout << setw(20) << pass;
		}

		void update_name(){
			cout << "\nEnter New Name: ";
			cin.getline(name, sizeof(name));
		}
		
		
};	// class ends

int Account::count=0;
char filename[] = "master_records.bin";

void login_page(){
	int choice;
	do{
		system("cls");
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "\t\t\t  CLI BANK MANAGEMENT SYSTEM\n";
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "1. Sign Up as User\n"
			 << "2. Login In as Admin\n"
			 << "3. Login In as Existing User\n"
			 << "4. Exit\n";
		cout << "Enter Choice: ";
		cin  >> choice;
		
		switch (choice){
		
			case 1:
				user_signup();
				break;
				
			case 2:
				admin_login();
				break;
				
			case 3:
				user_login();
				break;
			
			case 4:
				cout << "Exiting System\n";
				system("pause");
				break;
				
			default:
				cout << "\nInvalid Choice !\n";
				system("pause");
			}
	}while(choice!=4);
}

void admin_login(){
	do{
		system("cls");
		string username, pass;	char exitchoice;
		cout << "\n\t------------------------- Sign Up Page ------------------------\n\n";
		cout << "Enter Username(admin): ";
		cin  >> username;
		cout << "Enter Password(admin): ";
		cin  >> pass;
		if(username == "admin" && pass == "admin"){
			admin_mainmenu();
			system("pause");
			break;
		}
		cout << "Inavlid  Username or Password !\n";
		cout << "\nExit [y/n]: ";
		cin  >> exitchoice;
		if(exitchoice == 'y')	break;
	}while(true);
}

void admin_mainmenu(){
	int choice = 0;
	do{
		system("cls");
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	 	cout << "\t\t\tADMIN DASHBOARD\n";
	 	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	 	cout << "1. CREATE NEW ACCOUNT\n"
	 			"2. DEPOSIT IN ACCOUNT\n"
	 			"3. WITHDRAW FROM ACCOUNT\n"
	 			"4. VIEW ALL ACCOUNTS\n"
	 			"5. CHECK BALANCE\n"
	 			"6. UPDATE NAME\n"
	 			"7. EXIT";
	 	cout << "\nENTER TOUR CHOICE: ";
	 	cin  >> choice;
	 	switch(choice){
	 		case 1:		//add account
				new_acc();
				break;
	 		
	 		case 2:		//deposit in account
	 			deposit_in_acc();
				break;
	 			
	 		case 3:		//withdraw from account
	 			withdraw_from_acc();
				break;
	 			
	 		case 4:		//read full file
	 			view_all_acc();
				break;
	 		
	 		case 5:		//check  account balance
	 			check_balance();
	 			break;
	 		
	 		case 6:		//update accounnt holder name
	 			update_name();
	 			break;
	 			 			
			case 7:		//exit program
	            cout << "EXITING...\n";
	            break;
	            
	        default:
	            cout << "INVALID CHOICE\n";
		}
	}while(choice!=7);
}

void user_signup(){
	system("cls");
	cout << "\n\t------------------------- USER Sign Up Page ------------------------\n\n";
	new_acc();
}

void user_login(){
	system("cls");
	int acc_num;	string pass;	bool found = false;
		cout << "\n\t------------------------- USER LOGIN Page ------------------------\n\n";
		cout << "Enter Account Nummber: ";
		cin  >> acc_num;
	
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Enter Password: ";
		cin  >> pass;
		Account obj;
		ifstream file(filename, ios::binary | ios::in);
		if(!file){
			cout << "FILE OPENING FAILED!\n";
			system("pause");
			return;
		}
		while(file.read(reinterpret_cast<char*>(&obj), sizeof(obj))){
			if(acc_num == obj.get_acc_num() && pass == obj.get_pass()){
				file.close();
				user_mainmenu(acc_num);
				found = true;
				break;
			}
		}
		if(!found){
			cout << "\nInvalid Account nummber or Password !\n";
		}
		file.close();
		cout << "\nFILE CLOSED.\n";
		
		system("pause");
}

void user_mainmenu(int acc_num){
	int choice = 0;
	do{
		system("cls");
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	 	cout << "\t\t\tUSER DASHBOARD\n";
	 	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	 	cout << 
	 			"1. DEPOSIT IN ACCOUNT\n"
	 			"2. WITHDRAW FROM ACCOUNT\n"
	 			"3. CHECK BALANCE\n"
	 			"4. UPDATE NAME\n"
	 			"5. EXIT";
	 	cout << "\nENTER TOUR CHOICE: ";
	 	cin  >> choice;
	 	switch(choice){
	 		
	 		case 1:		//deposit in account
	 			deposit_in_acc(acc_num);
				break;
	 			
	 		case 2:		//withdraw from account
	 			withdraw_from_acc(acc_num);
				break;
	 		
	 		case 3:		//check  account balance
	 			check_balance(acc_num);
	 			break;
	 		
	 		case 4:		//update accounnt holder name
	 			update_name(acc_num);
	 			break;
	 			
			case 5:		//exit program
	            cout << "EXITING...\n";
	            break;
	            
	        default:
	            cout << "INVALID CHOICE\n";
		}
	}while(choice!=5);
}

void new_acc(){
	
	Account obj;
	int acc_num;	string pass;
	do{
	system("cls");
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
 	cout << "\t\t\tADD NEW ACCOUNT/ USER\n";
 	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
 	
 		cout << "ENTER ACCOUNT NUMBER(4digit only): ";
		cin  >> acc_num;
		if(acc_num > 9999 || acc_num < 1000){				//accnum must be between 1000 - 9999
			cout << "It should be betwen 1000 and 9999\n";
			system("pause");
		}
		}while(acc_num > 9999 || acc_num < 1000);
	
	ifstream file(filename, ios::binary | ios::in);
	if(file){
		while(file.read(reinterpret_cast<char*>(&obj), sizeof(obj))){	//file read to check if accnum already  exist or not
			if(acc_num == obj.get_acc_num()){
				cout << "\nACCOUNT NUMBER ALREADY EXIST !!\n";
				system("pause");
				return;
			}
		}
	}
	file.close();

	obj.new_acc(acc_num);
	ofstream fout(filename, ios::binary | ios::app);
	if(!fout){
		cout << "Error Opening File !\n";
		system("pause");
		return;
	}
	fout.write(reinterpret_cast<char*>(&obj), sizeof(obj));
	cout << "File Writing Completed.\n";
	system("pause");
	fout.close();
}

void deposit_in_acc(int acc_num){	//for user
	system("cls");
	cout << "++++++++++++++++++++++++++++++++++++++ DEPOSIT INTERFACE ++++++++++++++++++++++++++++++++++++++\n\n";
	Account obj;
	float deposit_amount;
	bool found = false;

	cout << "Enter Amount to Deposit: ";
	cin  >> deposit_amount;
	
	fstream file(filename, ios::binary | ios::in | ios::out);
	if(!file){
		cout << "FILE OPENING FAILED!\n";
		system("pause");
		return;
	}
	
	while(file.read(reinterpret_cast<char*>(&obj), sizeof(obj))){
		if(acc_num == obj.get_acc_num()){
			obj.deposit_in_acc(deposit_amount);
			file.seekp(-static_cast<int>(sizeof(obj)), ios::cur);
			file.write(reinterpret_cast<char*>(&obj), sizeof(obj));
			cout << "\nAMOUNT DEPOSITED!";
			found = true;
			break;
		}
	}
	if(!found){
		cout << "\nAccount Number not found.\n";
	}
	file.close();
	cout << "\nFILE CLOSED.";
	system("pause");
}

void deposit_in_acc(){	//for admin
	system("cls");
	cout << "++++++++++++++++++++++++++++++++++++++ DEPOSIT INTERFACE ++++++++++++++++++++++++++++++++++++++\n\n";
	Account obj;
	int acc_num;
	float deposit_amount;
	bool found = false;

	cout << "Enter Account Number: ";
	cin  >> acc_num;

	cout << "Enter Amount to Deposit: ";
	cin  >> deposit_amount;
	
	fstream file(filename, ios::binary | ios::in | ios::out);
	if(!file){
		cout << "FILE OPENING FAILED!\n";
		system("pause");
		return;
	}
	
	while(file.read(reinterpret_cast<char*>(&obj), sizeof(obj))){
		if(acc_num == obj.get_acc_num()){
			obj.deposit_in_acc(deposit_amount);
			file.seekp(-static_cast<int>(sizeof(obj)), ios::cur);
			file.write(reinterpret_cast<char*>(&obj), sizeof(obj));
			cout << "\nAMOUNT DEPOSITED!";
			found = true;
			break;
		}
	}
	if(!found){
		cout << "\nAccount Number not found.\n";
	}
	file.close();
	cout << "\nFILE CLOSED.";
	system("pause");
}	

void withdraw_from_acc(int acc_num){	//for user
	system("cls");
	float withdraw_amount;
	bool found = false;
	Account obj;
	cout << "++++++++++++++++++++++++++++++++++++++ WITHDRAW INTERFACE ++++++++++++++++++++++++++++++++++++++\n\n";
	
	cout << "Enter Amount to Withdraw: ";
	cin  >> withdraw_amount;
	
	fstream file(filename, ios::binary | ios::in | ios::out);
	if(!file){
		cout << "FILE OPENING FAILED!\n";
		system("pause");
		return;
	}
	while(file.read(reinterpret_cast<char*>(&obj), sizeof(obj))){
		if(acc_num == obj.get_acc_num()){
			if(withdraw_amount > obj.get_balance()){
				cout << "Insuficient Balance !\n";
				system("pause");
				file.close();
				return;
			}
			obj.withdraw_from_acc(withdraw_amount);
			file.seekp(-static_cast<int>(sizeof(obj)), ios::cur);
			file.write(reinterpret_cast<char*>(&obj), sizeof(obj));
			cout << "\nAMOUNT WITHDREW!";
			cout << "\tCurrent Balance: " << obj.get_balance();
			found = true;
			break;
		}
	}
	if(!found){
		cout << "\nAccount Number not found.\n";
	}
	file.close();
	cout << "\nFILE CLOSED.\n";
	
	system("pause");
	
}

void withdraw_from_acc(){	//for admin	
	system("cls");
	int acc_num;
	float withdraw_amount;
	bool found = false;
	Account obj;
	cout << "++++++++++++++++++++++++++++++++++++++ WITHDRAW INTERFACE ++++++++++++++++++++++++++++++++++++++\n\n";
	cout  << "Enter Account Number: ";
	cin   >> acc_num;
	
	cout << "Enter Amount to Withdraw: ";
	cin  >> withdraw_amount;
	
	fstream file(filename, ios::binary | ios::in | ios::out);
	if(!file){
		cout << "FILE OPENING FAILED!\n";
		system("pause");
		return;
	}
	while(file.read(reinterpret_cast<char*>(&obj), sizeof(obj))){
		if(acc_num == obj.get_acc_num()){
			if(withdraw_amount > obj.get_balance()){
				cout << "Insuficient Balance !\n";
				system("pause");
				file.close();
				return;
			}
			obj.withdraw_from_acc(withdraw_amount);
			file.seekp(-static_cast<int>(sizeof(obj)), ios::cur);
			file.write(reinterpret_cast<char*>(&obj), sizeof(obj));
			cout << "\nAMOUNT WITHDREW!";
			cout << "\tCurrent Balance: " << obj.get_balance();
			found = true;
			break;
		}
	}
	if(!found){
		cout << "\nAccount Number not found.\n";
	}
	file.close();
	cout << "\nFILE CLOSED.\n";
	
	system("pause");
	
}

void view_all_acc(){
	system("cls");
	cout << "----------------------------- VIEW ALL ACCOUNTS -----------------------------" << endl;
	Account obj;
	ifstream fin(filename, ios::binary | ios::in);
	if(!fin){
		cout << "Error Opening File !\n";
		system("pause");
		return;
	}
	while(fin.read(reinterpret_cast<char*>(&obj), sizeof(obj))){
		obj.display_details();
	}
	cout << endl;
	system("pause");
}

void check_balance(int acc_num){		//for user
	system("cls");
	bool found = false;
	Account obj;
	cout << "+++++++++++++++++++++++++++++++++++++++ BALANCE CHECKER ++++++++++++++++++++++++++++++++++++++\n\n";
	
	ifstream file(filename, ios::binary | ios::in);
	if(!file){
		cout << "FILE OPENING FAILED!\n";
		system("pause");
		return;
	}
	while(file.read(reinterpret_cast<char*>(&obj), sizeof(obj))){
		if(acc_num == obj.get_acc_num()){
			cout << "Current Balance is: " << obj.get_balance();
			found = true;
		}
	}
	if(!found){
		cout << "\nAccount Number not found.\n";
	}
	file.close();
	cout << "\nFILE CLOSED.\n";
	
	system("pause");
}

void check_balance(){		//for admin
	system("cls");
	
	int acc_num;
	bool found = false;
	Account obj;
	cout << "+++++++++++++++++++++++++++++++++++++++ BALANCE CHECKER ++++++++++++++++++++++++++++++++++++++\n\n";
	cout  << "Enter Account Number: ";
	cin   >> acc_num;
	
	ifstream file(filename, ios::binary | ios::in);
	if(!file){
		cout << "FILE OPENING FAILED!\n";
		system("pause");
		return;
	}
	while(file.read(reinterpret_cast<char*>(&obj), sizeof(obj))){
		if(acc_num == obj.get_acc_num()){
			cout << "Current Balance is: " << obj.get_balance();
			found = true;
		}
	}
	if(!found){
		cout << "\nAccount Number not found.\n";
	}
	file.close();
	cout << "\nFILE CLOSED.\n";
	
	system("pause");
}

void update_name(int acc_num){			//for user
	system("cls");
	
	char name[50];
	bool found = false;
	Account obj;
	cout << "++++++++++++++++++++++++++++++++++++++ UPDATE HOLDER'S NAME ++++++++++++++++++++++++++++++++++++++\n\n";
	
	fstream file(filename, ios::binary | ios::in | ios::out);
	if(!file){
		cout << "FILE OPENING FAILED!\n";
		system("pause");
		return;
	}
	while(file.read(reinterpret_cast<char*>(&obj), sizeof(obj))){
		if(acc_num == obj.get_acc_num()){
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			obj.update_name();
			file.seekp(-static_cast<int>(sizeof(obj)), ios::cur);
			file.write(reinterpret_cast<char*>(&obj), sizeof(obj));
			found = true;
			cout << "\nName Updated !";
		}
	}
	if(!found){
		cout << "\nAccount Number not found.\n";
	}
	file.close();
	cout << "\nFILE CLOSED.\n";
	
	system("pause");
}

void update_name(){			//for admin
	system("cls");
	
	int acc_num;
	char name[50];
	bool found = false;
	Account obj;
	cout << "++++++++++++++++++++++++++++++++++++++ UPDATE HOLDER'S NAME ++++++++++++++++++++++++++++++++++++++\n\n";
	cout  << "Enter Account Number: ";
	cin   >> acc_num;
	
	fstream file(filename, ios::binary | ios::in | ios::out);
	if(!file){
		cout << "FILE OPENING FAILED!\n";
		system("pause");
		return;
	}
	while(file.read(reinterpret_cast<char*>(&obj), sizeof(obj))){
		if(acc_num == obj.get_acc_num()){
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			obj.update_name();
			file.seekp(-static_cast<int>(sizeof(obj)), ios::cur);
			file.write(reinterpret_cast<char*>(&obj), sizeof(obj));
			found = true;
			cout << "\nName Updated !";
		}
	}
	if(!found){
		cout << "\nAccount Number not found.\n";
	}
	file.close();
	cout << "\nFILE CLOSED.\n";
	
	system("pause");
}

void close_acc(){
	system("cls");
	int acc_num;
	bool found = false;
	Account obj;
	
	cout << "Enter Account Number: ";
	cin  >> acc_num;
	
	ifstream fin(filename, ios::binary | ios::in);
	if(!fin){
		cout << "FILE OPENING FAILED !\n";
		system("pause");
	}
	ofstream fout("temp.bin", ios::binary | ios::out);
	if(!fout){
		cout << "FILE OPENING FAILED !";
	}
	while(fin.read(reinterpret_cast<char*>(&obj), sizeof(obj))){
		if(obj.get_acc_num() == acc_num){
			found = true;
			continue;
		}
		fout.write(reinterpret_cast<char*>(&obj), sizeof(obj));
	}
	fout.close();
	fin.close();
	if(found){
		cout << "\nAccount Deleted Successfully !\n";
		remove(filename);
		rename("temp.bin", filename);
		system("pause");
	}
	else{
		remove("temp.bin");
		cout << "\nAccount Not Found !\n";
		system("pause");
	}
}

int main(){
	login_page();
	return 0;
}
