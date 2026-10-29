#include "student.h"

int main() {
  student s;

  cout << "--- Adding Student Records ---" << endl;
  s.add_student(101, "Aarav Sharma", "A", 88.5);
  s.add_student(102, "Ananya Verma", "B", 92.0);
  s.add_student(103, "Rohan Kulkarni", "A", 72.4);

  // Displaying all records
  s.display();

  // Searching for a student
  s.search(102);
  s.search(999); // Non-existent student

  // Removing a student record
  s.remove_student(101);

  // Displaying records after removal
  s.display();

  return 0;
}