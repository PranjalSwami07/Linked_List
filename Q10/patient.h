/* Implement a patient management system using a singly linked list. Each node
stores the Patient ID, Patient Name, Age, and Illness.Perform the following
operations:
1. Register a new patient.
2. 3. 4. Remove a patient after consultation.
Display all patients in the queue.
Search for a patient using the Patient ID*/

#include <iostream>
#include <string>

using namespace std;

// Structure for a Patient Node
struct node {
  int patient_id;
  string name;
  int age;
  string illness;
  node *next;
};

// Class definition for Patient Management System
class patient {
  node *head;

public:
  patient();
  void register_patient(int id, string n, int a,
                        string ill); // 1. Register a new patient
  void remove_patient(int id);       // 2. Remove patient after consultation
  void display();                    // 3. Display all patients in queue
  void search(int id);               // 4. Search by Patient ID
};