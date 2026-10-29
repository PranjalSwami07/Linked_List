#include "coach.h"

coach ::coach() {
  head = NULL;
  tail = NULL;
}

void coach ::add_front(int num, string type) {
  node *nn = new node;
  if (!nn)
    return;

  nn->coach_no = num;
  nn->coach_type = type;
  nn->prev = NULL;
  nn->next = NULL;

  if (!head) {
    head = nn;
    tail = nn;
  } else {
    head->prev = nn;
    head = nn;
  }
  cout << "coach " << num << " added at the front." << endl;
}

void coach ::add_rear(int num, string type) {
  node *nn = new node;
  if (!nn)
    return;

  nn->coach_no = num;
  nn->coach_type = type;
  nn->prev = tail;
  nn->next = NULL;

  if (!head) {
    head = nn;
    tail = nn;
  } else {
    tail->next = nn;
    tail = nn;
  }
  cout << "Coach " << num << " added at rear." << endl;
}

void coach ::add_at_position(int num, string type, int pos) {
  if (pos <= 1 || !head) {
    add_front(num, type);
    return;
  }
  node *ptr = head;
  int current_pos = 1;

  while (ptr && current_pos < pos - 1) {
    ptr = ptr->next;
    current_pos++;
  }
  if (!ptr || !ptr->next) {
    add_rear(num, type);
    return;
  }

  node *nn = new node;
  nn->coach_no = num;
  nn->coach_type = type;
  nn->next = ptr->next;
  nn->prev = ptr;
  ptr->next->prev = nn;
  ptr->next = nn;

  cout << "Coach " << num << " added at position" << pos << "." << endl;
}

void coach ::remove(int num) {
  node *ptr = head;

  while (ptr) {
    if (ptr->coach_no == num) {
      if (ptr == head && ptr == tail) {
        head = NULL;
        tail = NULL;
      } else if (ptr == head) {
        head = head->next;
        head->prev = NULL;
      } else if (ptr == tail) {
        tail = tail->prev;
        tail->next = NULL;
      } else {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
      }
      delete ptr;
      cout << "Coach " << num << "successfully removed!" << endl;
      return;
    }
    ptr = ptr->next;
  }
  cout << "Coach " << num << "not found!" << endl;
}

void coach ::search(int num) {
  cout << "------------seaching-------------" << endl;
  node *ptr = head;
  while (ptr) {
    if (ptr->coach_no == num) {
      cout << "Coach " << num << " found!" << endl;
      return;
    }
    ptr = ptr->next;
  }
  cout << " Coach number" << num << "not found!" << endl;
}

void coach ::display_rear_to_front() {
  node *ptr = tail;
  cout << "----------Train Structure (Rear to Front)-----------" << endl;
  if (!tail) {
    cout << "No coaches attached!" << endl;
    return;
  }
  while (ptr) {
    cout << "[Coach No: " << ptr->coach_no << " | Type: " << ptr->coach_type
         << "]";
    if (ptr->prev)
      cout << " <== ";
    ptr = ptr->prev;
  }
  cout << " ==> [ENGINE]" << endl;
  cout << "----------------------------------" << endl;
}