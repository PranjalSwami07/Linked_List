/* A railway department maintains train coaches using a Doubly Linked List.Each
node stores: Coach Number ,Coach Type (AC/Sleeper/General). Implement the
following operations:
1. Add a coach at the front, rear, or specific position.
2. Remove a coach.
3. Search for a coach number.
4. Display coaches from last coach to engine.*/

#include <iostream>
#include <string>
using namespace std;

struct node {
  int coach_no;
  string coach_type;
  node *prev;
  node *next;
};

class coach {
  node *head;
  node *tail;

public:
  coach();
  void add_front(int num, string type);
  void add_rear(int num, string type);
  void add_at_position(int num, string type, int pos);

  void remove(int num);

  void search(int num);

  void display_rear_to_front();
  void display_front_to_rear();
};
