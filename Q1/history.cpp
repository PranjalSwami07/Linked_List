#include "history.h"

// constructor
history::history(int max_limit) {
  head = NULL;
  tail = NULL;
  count = 0;
  limit = max_limit;
}

void history ::add_action(int id, string desc) {
  node *nn = new node;
  if (!nn)
    return;

  nn->action_id = id;
  nn->description = desc;
  nn->next = NULL;
  nn->prev = NULL;

  // if empty list
  if (!head) {
    head = nn;
    tail = nn;
  } else {
    tail->next = nn;
    nn->prev = tail;
    tail = nn;
  }

  count++;

  if (count > limit) {
    node *temp = head;
    head = head->next;
    if (head) {
      head->prev = NULL;
    }
    delete temp;
    count--;
    cout << "History limit reached!Oldest action removed" << endl;
  }
  cout << "Action added to history" << endl;
}

void history ::search(int id) {
  node *ptr = head;
  cout << "----------------searching action------------------" << endl;
  while (ptr) {
    if (ptr->action_id == id) {
      cout << "action found!" << endl;
      cout << "Action Id:" << ptr->action_id
           << ",Description: " << ptr->description << endl;
      return;
    }
    ptr = ptr->next;
  }
  cout << "Action ID: " << id << " not found in history" << endl;
}

void history ::display() {
  node *ptr = head;
  cout << "---------Editing history----------" << endl;
  if (!head) {
    cout << "No history available!" << endl;
    return;
  }
  while (ptr) {
    cout << "[Action Id: " << ptr->action_id << "]" << ptr->description << endl;
    ptr = ptr->next;
  }
  cout << "-----------------------------------------" << endl;
}
