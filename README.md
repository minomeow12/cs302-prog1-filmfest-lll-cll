# CS302 Program 1 – Film Festival Management (Linked Lists)

## Overview
This project is a menu-driven C++ application that simulates managing events
for a film festival. The program demonstrates fundamental data structures
and object-oriented programming concepts, including dynamic memory management,
recursion, and linked lists.

The application allows users to manage different types of festival events
such as screenings, workshops, and merchandise booths using linear and
circular linked lists.

---

## Key Concepts and Skills
- Object-Oriented Programming (OOP) in C++
- Inheritance and polymorphism
- Linear Linked List (LLL)
- Circular Linked List (CLL)
- Recursion
- Dynamic memory allocation
- Menu-driven user interface
- Modular program design with header/source separation

---

## Project Structure
.
├── src/
│ ├── main.cpp
│ ├── menu.cpp
│ ├── data_structure.cpp
│ ├── Event.cpp
│ ├── MerchBooth.cpp
│ ├── Screening.cpp
│ ├── Workshop.cpp
│ └── Node.cpp
│
├── include/
│ ├── menu.h
│ ├── List.h
│ ├── FilmFest.h
│ └── Node.h
│
├── README.md
└── .gitignore

yaml
Copy code

---

## How to Compile
Make sure you are in the project root directory.
g++ -Wall -std=c++17 src/*.cpp -I include -o prog1

## How to Run
After compiling:
./prog1

Program Features
Add, display, and manage film festival events

Uses inheritance to represent different event types

Implements linked lists to store and manage data

Recursive functions for traversal and cleanup

Clean separation of interface (.h) and implementation (.cpp)

Learning Outcomes
Through this project, I strengthened my understanding of:

Implementing linked lists from scratch

Designing class hierarchies in C++

Managing memory safely using constructors and destructors

Structuring medium-sized C++ programs

Using Git and GitHub for version control
