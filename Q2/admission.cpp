#include "admission.h"
#include <ostream>

admission ::admission() { head = NULL; }

void admission ::add_applicant(int id, string n, float score) {
  node *nn = new node;
  if (!nn)
    return;

  nn->applicant_id = id;
  nn->name = n;
  nn->entrance_score = score;
  nn->next = NULL;

  // Adding at LAst
  if (!head) {
    head = nn;
    cout << "Applicant record added successfully!" << endl;
    return;
  }
  node *ptr = head;
  while (ptr->next) {
    ptr = ptr->next;
  }
  ptr->next = nn;
  cout << "Applicant record added successfully!" << endl;
}

void admission ::display() {
  node *ptr = head;
  cout << "------Applicant Record--------" << endl;
  if (!head) {
    cout << "No Applicant! " << endl;
    return;
  }
  while (ptr) {
    cout << "Applicant ID   :" << ptr->applicant_id << endl;
    cout << "Name           :" << ptr->name << endl;
    cout << "Score          :" << ptr->entrance_score << endl;
    cout << "--------------------------------" << endl;
    ptr = ptr->next;
  }
}
// Sorting by data
void admission ::sort_by_id() {
  if (!head || head->next) {
    cout << "List is empty or has only one record, so no sorting required."
         << endl;
    return;
  }

  node *i;
  node *j;

  for (i = head; i != NULL; i = i->next) {
    for (j = i->next; j != NULL; j = j->next) {
      if (i->applicant_id > j->applicant_id) {
        // Swap ID
        int temp_id = i->applicant_id;
        i->applicant_id = j->applicant_id;
        j->applicant_id = temp_id;

        // swap names
        string temp_name = i->name;
        i->name = j->name;
        j->name = temp_name;

        // Swap Score
        float temp_score = i->entrance_score;
        i->entrance_score = j->entrance_score;
        j->entrance_score = temp_score;
      }
    }
  }
  cout << "List Sorted! " << endl;
}