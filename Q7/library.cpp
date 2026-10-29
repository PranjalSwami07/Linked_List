#include "library.h"

// Constructor initializing head pointer to NULL
library::library() { head = NULL; }

// a. Add a new book to the catalogue
void library::add_book(int id, string t, string a, bool status) {
  node *nn = new node;
  if (!nn)
    return;

  nn->book_id = id;
  nn->title = t;
  nn->author = a;
  nn->is_available = status;
  nn->next = NULL;

  // If list is empty
  if (!head) {
    head = nn;
    cout << "Book '" << t << "' added to catalogue successfully!" << endl;
    return;
  }

  // Traverse to the end and insert
  node *ptr = head;
  while (ptr->next) {
    ptr = ptr->next;
  }
  ptr->next = nn;
  cout << "Book '" << t << "' added to catalogue successfully!" << endl;
}

// b. Remove a book from the catalogue by Book ID
void library::remove_book(int id) {
  cout << "----------------- Removing Book -----------------" << endl;
  node *ptr = head;
  node *pptr = NULL;

  while (ptr) {
    if (ptr->book_id == id) {
      if (pptr) {
        pptr->next = ptr->next; // Node is in the middle or end
      } else {
        head = ptr->next; // Node is head
      }
      cout << "Removed Book: " << ptr->title << " by " << ptr->author << endl;
      delete ptr; // Free memory
      return;
    }
    pptr = ptr;
    ptr = ptr->next;
  }
  cout << "Book ID " << id << " not found in catalogue!" << endl;
}

// c. Display all available books
void library::display_available() {
  node *ptr = head;
  cout << "\n----------------- Available Books -----------------" << endl;
  if (!head) {
    cout << "Catalogue is empty!" << endl;
    return;
  }

  bool found = false;
  while (ptr) {
    if (ptr->is_available) {
      found = true;
      cout << "Book ID : " << ptr->book_id << endl;
      cout << "Title   : " << ptr->title << endl;
      cout << "Author  : " << ptr->author << endl;
      cout << "Status  : Available" << endl;
      cout << "---------------------------------------------------" << endl;
    }
    ptr = ptr->next;
  }

  if (!found) {
    cout << "No books are currently available." << endl;
  }
}

// d. Search for a book using the Book ID
void library::search(int id) {
  cout << "\n----------------- Searching Book -----------------" << endl;
  node *ptr = head;
  while (ptr) {
    if (ptr->book_id == id) {
      cout << "Book Found!" << endl;
      cout << "Book ID : " << ptr->book_id << endl;
      cout << "Title   : " << ptr->title << endl;
      cout << "Author  : " << ptr->author << endl;
      cout << "Status  : " << (ptr->is_available ? "Available" : "Checked Out")
           << endl;
      return;
    }
    ptr = ptr->next;
  }
  cout << "Book ID " << id << " not found in catalogue!" << endl;
}