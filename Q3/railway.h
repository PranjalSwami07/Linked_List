/*Implement a railway waiting list using a singly linked list (SLL). Each node
stores the Passenger ID,Passenger Name and Age.Perform the following operations:
1.Add a new passenger at the end of the waiting list.
2.Delete a passenger from the front when the ticket is confirmed.
3.Display all passengers in the waiting list.
4.Search the record by Passenger ID*/

#include <iostream>
#include <string>
using namespace std;

struct node {
  int passenger_id;
  string name;
  int age;
  node *next;
};

class railway {
  node *head;

public:
  railway();
  void add_passenger(int id, string n, int a); // adding at end
  void delete_front();
  void display();
  void search(int id);
};