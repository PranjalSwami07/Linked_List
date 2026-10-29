#include "patient.h"

// Constructor initializing head pointer
patient::patient() { head = NULL; }

// 1. Register a new patient (Add to end of queue)
void patient::register_patient(int id, string n, int a, string ill) {
  node *nn = new node;
  if (!nn)
    return;

  nn->patient_id = id;
  nn->name = n;
  nn->age = a;
  nn->illness = ill;
  nn->next = NULL;

  // If queue is empty
  if (!head) {
    head = nn;
    cout << "Patient " << n << " registered successfully!" << endl;
    return;
  }

  // Traverse to the end and insert
  node *ptr = head;
  while (ptr->next) {
    ptr = ptr->next;
  }
  ptr->next = nn;
  cout << "Patient " << n << " registered successfully!" << endl;
}

// 2. Remove a patient after consultation using Patient ID
void patient::remove_patient(int id) {
  cout << "----------------- Removing Patient -----------------" << endl;
  node *ptr = head;
  node *pptr = NULL;

  while (ptr) {
    if (ptr->patient_id == id) {
      if (pptr) {
        pptr->next = ptr->next; // Node is in middle or end
      } else {
        head = ptr->next; // Node is head
      }
      cout << "Patient Consultation Completed: " << ptr->name
           << " (ID: " << ptr->patient_id << ")" << endl;
      delete ptr; // Free memory
      return;
    }
    pptr = ptr;
    ptr = ptr->next;
  }
  cout << "Patient ID " << id << " not found!" << endl;
}

// 3. Display all patients in the queue
void patient::display() {
  node *ptr = head;
  cout << "\n----------------- Current Patient Queue -----------------" << endl;
  if (!head) {
    cout << "No patients in the queue!" << endl;
    return;
  }
  while (ptr) {
    cout << "Patient ID : " << ptr->patient_id << endl;
    cout << "Name       : " << ptr->name << endl;
    cout << "Age        : " << ptr->age << endl;
    cout << "Illness    : " << ptr->illness << endl;
    cout << "--------------------------------------------------------" << endl;
    ptr = ptr->next;
  }
}

// 4. Search for a patient using Patient ID
void patient::search(int id) {
  cout << "\n----------------- Searching Patient -----------------" << endl;
  node *ptr = head;
  while (ptr) {
    if (ptr->patient_id == id) {
      cout << "Patient Found!" << endl;
      cout << "Patient ID : " << ptr->patient_id << endl;
      cout << "Name       : " << ptr->name << endl;
      cout << "Age        : " << ptr->age << endl;
      cout << "Illness    : " << ptr->illness << endl;
      return;
    }
    ptr = ptr->next;
  }
  cout << "Patient with ID " << id << " not found in the queue!" << endl;
}