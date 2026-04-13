#include<fstream>
#include<iostream>
using namespace std;

int main()
{
 	//----------------------- File Writing(line -by- line) -----------------------
 	string word;
	char filename[20];
 	cout << "WRITING IN A TEXT FILE\n";
 	cout << "==============================================\n\n";
 	cout << "Enter a FileName with Extension: ";
 	cin  >> filename;
 	
 	ofstream fout(filename, ios::out);			// file opening...
 	if(!fout.is_open()){						// check if error in opening file...
 		cout << "ERROR OPENING THE FILE.";
	 }
	 
	cout << "FILE OPENED SUCCESSFULLY, START WRITING, type END to stop\n";
	cin.ignore();
	while(true){						// writing to file
		getline(cin, word);
		if(word == "END") break;
		fout << word << "\n";
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
	
	cout << "\n-------------- FILE READing -----------------\n";
	
	while(getline(fin, word)){						// reading from file
		
		cout << word << "\n";
	}
	
	fin.close();							// file closing...
	cout << "\n-------------- FILE READing Ended-----------------\n";
	return 0;
}
