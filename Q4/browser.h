/*Implement a web browser tab management system using a doubly linked list
(DLL). Each node stores the URL of an open tab.Perform the following operations:
1. 2. 3. 4. Insert: Add a new tab to the browser.
Move Backward: Move to the previous tab.
Search: Find a tab using its URL.
Display: Display all open tabs.*/

#include <iostream>
#include <string>
using namespace std;

struct node {
  string url;
  node *next;
  node *prev;
};

class browser {
  node *head;
  node *tail;
  node *current;

public:
  browser();
  void add_tab(string u);
  void move_backward();
  void search(string u);
  void display();
};