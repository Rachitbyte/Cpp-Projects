# Number File Processing System (C++)

## Overview

This is a command-line based C++ program that demonstrates file handling and basic number processing. It generates numbers from 1 to N, stores them in a file, and then processes them to identify odd and prime numbers.

The results are stored in separate files and displayed side-by-side.

---

## Features

* Generate numbers from 1 to N
* Store numbers in a text file (`numbers.txt`)
* Identify and store:

  * Odd numbers → `oddnumbers.txt`
  * Prime numbers → `primenumbers.txt`
* Display odd and prime numbers in parallel format

---

## Workflow

1. User inputs a number `N`
2. Program writes numbers `1 → N` into `numbers.txt`
3. Reads the file and:

   * Filters odd numbers
   * Checks for prime numbers
4. Writes results into:

   * `oddnumbers.txt`
   * `primenumbers.txt`
5. Displays both outputs side-by-side

---

## Concepts Used

### 1. File Handling

* `ofstream` → writing to files
* `ifstream` → reading from files
* Multiple file streams handling

### 2. Functions

* Separate function for prime number checking:

  * `isPrime(int)`

### 3. Control Structures

* Loops (`for`, `while`)
* Conditional statements (`if`)

### 4. Basic Algorithms

* Prime number checking using √n optimization
* Odd number detection using modulus operator

---

## Files Used

* `numbers.txt` → stores numbers from 1 to N
* `oddnumbers.txt` → stores odd numbers
* `primenumbers.txt` → stores prime numbers

---

## How to Run

1. Compile the program:

   ```
   g++ main.cpp -o program
   ```

2. Run the executable:

   ```
   ./program
   ```

3. Enter the value of `N` when prompted

---

## Sample Output

```
ODD NUMBERS     PRIME NUMBERS

1               2
3               3
5               5
7               7
...
```

---

## Limitations

* No input validation (negative or invalid input not handled)
* Files are overwritten on each run
* Single-file implementation (no modular structure)

---

## Purpose

This project is intended for practicing:

* File handling in C++
* Basic number processing
* Working with multiple files
* Simple algorithm implementation

---

## Author

Rachit