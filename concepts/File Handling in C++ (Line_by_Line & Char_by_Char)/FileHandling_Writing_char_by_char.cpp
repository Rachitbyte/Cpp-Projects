#include<fstream>
#include<iostream>
using namespace std;

int main()
{
 	//----------------------- File Writing (char -by- char) -----------------------
 	char ch, filename[20];
 	cout << "WRITING IN A TEXT FILE\n";
 	cout << "==============================================\n\n";
 	cout << "Enter a FileName with Extension: ";
 	cin  >> filename;
 	
 	ofstream fout(filename, ios::out);			// file opening...
 	if(!fout.is_open()){						// check if error in opening file...
 		cout << "ERROR OPENING THE FILE.";
	 }
	 
	cout << "FILE OPENED SUCCESSFULLY, START WRITING, press * to stop\n";
	cin.ignore();
	while(ch!='*'){
	    ch = getchar();
	 	if(ch != '*'){
	 		fout << ch;
		 }
	}
	 
	fout.close();
	cout << "\nFILE CLOSED !\n";
	 
	//----------------------- File Reading -----------------------
	cout << "Enter a Filenme To Read: ";
	cin  >> filename;
	 
	ifstream fin(filename, ios::in);		// file opening...
	if(!fin.is_open()){						// check if error in opening file...
		cout << "Error OPENING in File...\n";
	}
	while(fin.get(ch)){						// reading from file
		cout << ch;
	}
	
	fin.close();							// file closing...
	return 0;
}
