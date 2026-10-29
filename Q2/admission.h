/* Implement a college admission management system using a singly linked list
(SLL). Each node stores the Applicant ID, Name, and Entrance Score. Create nodes
dynamically as new applications are received.Perform the following operations:
1. 2. 3. Add a new applicant record dynamically.
Display all applicant records using traversal.
Sort the SLL using Applicant ID. */

#include <iostream>
#include <string>
using namespace std;

struct node {
  int applicant_id;
  string name;
  float entrance_score;
  node *next;
};

class admission {
  node *head;

public:
  admission();
  void add_applicant(int id, string n, float score);
  void display();
  void sort_by_id();
};