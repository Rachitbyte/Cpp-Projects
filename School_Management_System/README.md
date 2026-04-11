# School Management System (C++)

## Overview

This is a command-line based School Management System implemented in C++. The project demonstrates multiple Object-Oriented Programming (OOP) concepts along with basic file handling.

It allows managing student records with persistent storage and showcases different types of inheritance in a structured way.

---

## Features

### Student Management (File-Based)

 Add student records
 View all students
 Search student by ID

### Inheritance Demonstration

 ClassMonitor (Multilevel Inheritance)
 Teacher and Staff (Hierarchical Inheritance)
 Result system (Multiple Inheritance)

---

## Concepts Used

### 1. Object-Oriented Programming (OOP)

 Classes and objects
 Encapsulation
 Inheritance

### 2. Types of Inheritance

 Single Inheritance → `Student → Person`
 Multilevel Inheritance → `ClassMonitor → Student → Person`
 Hierarchical Inheritance → `Teacher`, `Staff → Person`
 Multiple Inheritance → `Result → Exam + Sports`

### 3. File Handling (Binary Files)

 `ofstream`, `ifstream`, `fstream`
 Persistent storage using `school.dat`
 Basic CRUD operations (Add, View, Search)

### 4. Menu-Driven Programming

 Interactive CLI interface using switch-case

---

## File Structure

```bash
school-management-system-cpp
│
├── main.cpp
├── school.dat (generated at runtime)
└── README.md
```

---

## How to Run

1. Compile the program

   ```
   g++ main.cpp -o school
   ```

2. Run

   ```
   .school
   ```

---

## Sample Menu

```
===== SCHOOL SYSTEM =====
1. Add Student
2. View Students
3. Search Student
4. Demonstrate Inheritance
5. Exit
```

---

## Limitations

 Uses binary file storage (not portable across systems)
 Only Student records are stored in file
 No updatedelete functionality for all classes
 Uses `char[]` instead of `string`
 Single-file implementation

---

## Purpose

This project is built for

 Practicing C++ OOP concepts
 Understanding different types of inheritance
 Learning basic file handling
 Building menu-driven applications

---

## Author

Rachit