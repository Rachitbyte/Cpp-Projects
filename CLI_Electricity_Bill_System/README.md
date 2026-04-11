# CLI Electricity Bill System (C++)

## Overview

This is a command-line based Electricity Bill Management System implemented in C++. It calculates electricity charges based on unit consumption using slab rates and generates a formatted bill report.

The project is built as a practice exercise to strengthen understanding of object-oriented programming, static members, and formatted console output.

---

## Features

* Input multiple consumer records
* Calculate electricity charges using slab-based pricing
* Apply GST (12%) on total charges
* Display formatted bill details in tabular form
* Compute overall statistics:

  * Total charges
  * Total GST collected
  * Final bill amount
  * Average units consumed

---

## Billing Logic

Electricity charges are calculated using the following slabs:

* 0–100 units → ₹1.5 per unit
* 101–300 units → ₹3.5 per unit
* 301–600 units → ₹4.5 per unit
* Above 600 units → ₹6.75 per unit

GST of 12% is applied on the total charges.

---

## Concepts Used

### 1. Object-Oriented Programming (OOP)

* Class (`eBill`)
* Encapsulation (private data + public methods)
* Member functions

### 2. Static Members

* Used to track:

  * Total units
  * Total charges
  * Total GST
  * Final bill amount
  * Entry count

### 3. Vectors (Dynamic Arrays)

* `vector<eBill>` used for handling multiple records dynamically

### 4. Control Structures

* Conditional statements (`if-else`)
* Loops (`for`)

### 5. Formatted Output

* `setw()` for alignment
* `fixed` and `setprecision()` for decimal formatting

### 6. Basic Input/Output

* `cin` / `cout` for user interaction

---

## Technologies Used

* Language: C++
* Standard Library: STL (`vector`, `iomanip`)
* Platform: Console (CLI)

---

## How to Run

1. Compile the program:

   ```
   g++ main.cpp -o ebill
   ```

2. Run the executable:

   ```
   ./ebill
   ```

---

## Sample Output

The program displays:

* A table of all consumers with charges and GST
* A summary including totals and averages

---

## Limitations

* No input validation (invalid values not handled)
* No file storage (data is not persistent)
* Uses `#include<bits/stdc++.h>` (non-standard header)
* Single-file implementation (no modular structure)

---

## Purpose

This project is intended for practicing:

* C++ fundamentals
* OOP concepts
* Static data handling
* Console-based UI formatting

---

## Author

Rachit
