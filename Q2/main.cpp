#include "admission.h"

int main() {
  admission college;

  cout << "--------Adding Applicant---------" << endl;
  college.add_applicant(101, "Abcc", 99);
  college.add_applicant(102, "Bcaa", 79);
  college.add_applicant(103, "Cabb", 85);

  college.display();
  college.sort_by_id();
  college.display();

  return 0;
}