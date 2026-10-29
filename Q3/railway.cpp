#include "railway.h"

railway ::railway() { head = NULL; }

// adding passenger at end
void railway ::add_passenger(int id, string n, int a) {
  node *nn = new node;
  if (!nn)
    return;
  nn->passenger_id = id;
  nn->name = n;
  nn->age = a;
  nn->next = NULL;

  // If empty list
  if (!head) {
    head = nn;
    cout << "Passenger added to list!" << endl;
    return;
  }
  node *ptr = head;
  while (ptr->next) {
    ptr = ptr->next;
  }
  ptr->next = nn;
  cout << "Passenger added to list!" << endl;
}

void railway ::delete_front() {
  cout << "---------Confirming tickets---------" << endl;
  if (!head) {
    cout << "No Passenger in list!" << endl;
    return;
  }

  node *temp = head;
  cout << "Ticket confirmed for Passenger ID :" << temp->passenger_id << endl;
  head = head->next;
  delete temp;
}

void railway ::display() {
  node *ptr = head;
  cout << "---------Waiting List---------" << endl;
  if (!head) {
    cout << "No Passenger" << endl;
    return;
  }
  while (ptr) {
    cout << "Passenger ID : " << ptr->passenger_id << endl;
    cout << "Passenger Name : " << ptr->name << endl;
    cout << "Passenger Age : " << ptr->age << endl;
    ptr = ptr->next;
    cout << "-----------------------------" << endl;
    ptr = ptr->next;
  }
}

void railway ::search(int id) {
  cout << "-----------Searching Passenger-------------" << endl;
  node *ptr = head;
  while (ptr) {
    if (ptr->passenger_id == id) {
      cout << "Passenger Found" << endl;
      cout << "Passenger ID : " << ptr->passenger_id << endl;
      cout << "Passenger Name : " << ptr->name << endl;
      cout << "Passenger Age : " << ptr->age << endl;
      return;
    }
    ptr = ptr->next;
  }
  cout << "Passenger ID" << id << "not Found" << endl;
}