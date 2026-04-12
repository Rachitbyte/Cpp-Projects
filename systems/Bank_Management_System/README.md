# CLI Bank Management System (C++)

## Overview

This is a command-line based Bank Management System implemented in C++. It simulates basic banking operations such as account creation, login, deposits, withdrawals, and account management for both users and admin.

The project is built as a practice exercise to apply core C++ concepts, file handling, and basic object-oriented design.

---

## Features

### User Features

* Sign up and create a new bank account
* Login using account number and password
* Deposit money
* Withdraw money
* Check account balance
* Update account holder name

### Admin Features

* Admin login (fixed credentials)
* Create new accounts
* Deposit and withdraw from any account
* View all accounts
* Check account balance
* Update account holder name
* Delete account

---

## Concepts Used

### 1. Object-Oriented Programming (OOP)

* Class and objects (`Account` class)
* Encapsulation (private data with public methods)
* Member functions

### 2. Function Overloading

* Same function name with different parameters:

  * `deposit_in_acc()`
  * `deposit_in_acc(int)`
  * `withdraw_from_acc()`
  * `withdraw_from_acc(int)`
  * `check_balance()`
  * `check_balance(int)`

### 3. File Handling (Binary Files)

* Reading and writing objects using:

  * `ifstream`
  * `ofstream`
  * `fstream`
* Persistent data storage in `master_records.bin`

### 4. Type Casting

* Use of `reinterpret_cast` for binary file operations

### 5. Control Structures

* Loops (`do-while`, `while`)
* Conditional statements (`if-else`, `switch`)
* Basic input validation

### 6. Static Members

* Static variable `count` used for formatting output

### 7. String Handling

* Use of C-style strings (`char[]`)
* Input handling with `cin`, `getline()`, and buffer management

### 8. Menu-Driven Program Design

* CLI-based navigation system using menus

---

## Technologies Used

* Language: C++
* Compiler: GCC / TDM-GCC / any standard C++ compiler
* Platform: Console (CLI)

---

## How to Run

1. Compile the code:

   ```
   g++ main.cpp -o bank
   ```

2. Run the executable:

   ```
   ./bank
   ```

---

## Notes

* Data is stored in a binary file (`master_records.bin`)
* Admin credentials are hardcoded:

  * Username: `admin`
  * Password: `admin`
* This project is for learning purposes and does not implement security features like encryption or hashing

---

## Limitations

* No data encryption (passwords stored as plain text)
* Platform-dependent functions (`system("cls")`, `system("pause")`)
* Uses binary file storage which is not portable across different systems/compilers
* No error handling for corrupted files

---

## Purpose

This project is intended for practicing:

* C++ fundamentals
* File handling
* Basic system design using CLI

---

## Author

Rachit