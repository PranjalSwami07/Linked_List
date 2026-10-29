#include "patient.h"

int main() {
  patient p;

  cout << "--- Registering Patients ---" << endl;
  p.register_patient(101, "Ramesh Kulkarni", 45, "Fever & Cold");
  p.register_patient(102, "Sita Sharma", 30, "Migraine");
  p.register_patient(103, "Vijay Patel", 60, "Diabetes Checkup");

  // Displaying patient queue
  p.display();

  // Searching for a patient
  p.search(102);

  // Removing a patient after consultation
  p.remove_patient(101);

  // Displaying updated queue
  p.display();

  return 0;
}