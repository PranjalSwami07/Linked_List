#include <iostream>
#include <string>
using namespace std;

struct node {
  int action_id;
  string description;
  node *prev;
  node *next;
};

class history {
  node *head;
  node *tail;
  int count;
  int limit;

public:
  history(int max_limit);
  void add_action(int id, string desc);
  void search(int id);
  void display();
};