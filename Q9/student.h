/* Implement a student attendance management system using a singly linked list.
Each node stores the Roll Number, Student Name, Division, and Attendance
Percentage.Perform the following operations:
1. Add a student record.
2. Remove a student record.
3. Display all student records.
4. Search for a student using the Roll Number.*/

#include <iostream>
#include <string>

using namespace std;

// Structure defining a Student Node in the Singly Linked List
struct node {
  int roll_number;
  string name;
  string division;
  float attendance_percentage;
  node *next;
};

// Class definition for Student Attendance Management
class student {
  node *head;

public:
  student();
  void add_student(int roll, string n, string div,
                   float attendance); // 1. Add student record
  void remove_student(int roll);      // 2. Remove student record
  void display();                     // 3. Display all records
  void search(int roll);              // 4. Search by Roll Number
};