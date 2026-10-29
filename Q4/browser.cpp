#include "browser.h"

browser ::browser() {
  head = NULL;
  tail = NULL;
  current = NULL;
}

void browser ::add_tab(string u) {
  node *nn = new node;
  if (!nn)
    return;

  nn->url = u;
  nn->prev = NULL;
  nn->next = NULL;

  if (!head) {
    head = nn;
    tail = nn;
  } else {
    tail->next = nn;
    nn->prev = tail;
    tail = nn;
  }
  current = nn;
  cout << "Currently opened tab: " << u << endl;
}

void browser ::move_backward() {
  if (!current) {
    cout << "No tabs are open!" << endl;
    return;
  }
  if (current->prev) {
    current = current->prev;
    cout << "Move backward to: " << current->url << endl;
  } else {
    cout << "Already at first tab(" << current->url
         << "). Cannot move backward!" << endl;
  }
}

void browser ::search(string u) {
  cout << "-----------Searching-------------" << endl;
  node *ptr = head;
  while (ptr) {
    if (ptr->url == u) {
      cout << "Tab Found! URL: " << ptr->url << endl;
      return;
    }
    ptr = ptr->next;
  }
  cout << "Tab with URL ' " << u << " ' not found!" << endl;
}

void browser ::display() {
  node *ptr = head;
  cout << "--------Open Browser tabs----------" << endl;

  if (!head) {
    cout << "No open tabs!" << endl;
    return;
  }
  while (ptr) {
    if (ptr == current) {
      cout << " -> " << ptr->url << " (Active tab)" << endl;
    } else {
      cout << "   " << ptr->url << endl;
    }
    ptr = ptr->next;
  }
  cout << "----------------------------------" << endl;
}