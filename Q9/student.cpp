#include "student.h"

// Constructor initializing head pointer to NULL
student::student() { head = NULL; }

// 1. Add a new student record
void student::add_student(int roll, string n, string div, float attendance) {
  node *nn = new node;
  if (!nn)
    return;

  nn->roll_number = roll;
  nn->name = n;
  nn->division = div;
  nn->attendance_percentage = attendance;
  nn->next = NULL;

  // If list is empty
  if (!head) {
    head = nn;
    cout << "Student record added successfully!" << endl;
    return;
  }

  // Traverse to the end and insert
  node *ptr = head;
  while (ptr->next) {
    ptr = ptr->next;
  }
  ptr->next = nn;
  cout << "Student record added successfully!" << endl;
}

// 2. Remove a student record by Roll Number
void student::remove_student(int roll) {
  cout << "----------------- Removing Student Record -----------------" << endl;
  node *ptr = head;
  node *pptr = NULL;

  while (ptr) {
    if (ptr->roll_number == roll) {
      if (pptr) {
        pptr->next = ptr->next; // Node is in the middle or end
      } else {
        head = ptr->next; // Node is the head
      }
      cout << "Removed Student: " << ptr->name
           << " (Roll No: " << ptr->roll_number << ")" << endl;
      delete ptr; // Free memory
      return;
    }
    pptr = ptr;
    ptr = ptr->next;
  }
  cout << "Student with Roll Number " << roll << " not found!" << endl;
}

// 3. Display all student records
void student::display() {
  node *ptr = head;
  cout << "\n----------------- Student Records -----------------" << endl;
  if (!head) {
    cout << "No student records available!" << endl;
    return;
  }
  while (ptr) {
    cout << "Roll Number : " << ptr->roll_number << endl;
    cout << "Name        : " << ptr->name << endl;
    cout << "Division    : " << ptr->division << endl;
    cout << "Attendance  : " << ptr->attendance_percentage << "%" << endl;
    cout << "---------------------------------------------------" << endl;
    ptr = ptr->next;
  }
}

// 4. Search for a student using Roll Number
void student::search(int roll) {
  cout << "\n----------------- Searching Student -----------------" << endl;
  node *ptr = head;
  while (ptr) {
    if (ptr->roll_number == roll) {
      cout << "Student Record Found!" << endl;
      cout << "Roll Number : " << ptr->roll_number << endl;
      cout << "Name        : " << ptr->name << endl;
      cout << "Division    : " << ptr->division << endl;
      cout << "Attendance  : " << ptr->attendance_percentage << "%" << endl;
      return;
    }
    ptr = ptr->next;
  }
  cout << "Student with Roll Number " << roll << " not found!" << endl;
}