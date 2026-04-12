#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    int n, number, number2;

    cout << "Storing first N numbers in a text file.\n\n";
    cout << "Enter n: ";
    cin >> n;

    // Create numbers file
    ofstream numbersFile("numbers.txt");
    if (!numbersFile) {
        cout << "Error opening numbers.txt\n";
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        numbersFile << i << endl;
    }
    numbersFile.close();

    // Open files
    ifstream inputFile("numbers.txt");
    ofstream oddFile("oddnumbers.txt");
    ofstream primeFile("primenumbers.txt");

    if (!inputFile || !oddFile || !primeFile) {
        cout << "Error opening files\n";
        return 1;
    }

    // Process numbers
    while (inputFile >> number) {

        if (number % 2 != 0) {
            oddFile << number << endl;
        }

        if (isPrime(number)) {
            primeFile << number << endl;
        }
    }

    inputFile.close();
    oddFile.close();
    primeFile.close();

    // Read and display side-by-side
    ifstream oddRead("oddnumbers.txt");
    ifstream primeRead("primenumbers.txt");

    if (!oddRead || !primeRead) {
        cout << "Error opening output files\n";
        return 1;
    }

    cout << "\nODD NUMBERS\tPRIME NUMBERS\n\n";

    while (true) {
        bool hasOdd = bool(oddRead >> number);
        bool hasPrime = bool(primeRead >> number2);

        if (!hasOdd && !hasPrime) break;

        if (hasOdd) cout << number;
        cout << "\t\t";

        if (hasPrime) cout << number2;
        cout << endl;
    }

    oddRead.close();
    primeRead.close();

    return 0;
}
