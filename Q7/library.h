/*Consider the catalogue of books in a library. Implement a library catalogue
management system using a singly linked list. Each book is represented as a node
in the linked list. Each node contains information such as Book ID, Book Title,
Author, and Availability Status.Implement the following operations: a. Add a new
book b. Remove a book from the catalogue c. Display all available books d.
Search for a book using the Book ID*/

#include <iostream>
#include <string>

using namespace std;

// Structure defining a Book Node in the Singly Linked List
struct node {
  int book_id;
  string title;
  string author;
  bool is_available;
  node *next;
};

// Class definition for Library Catalogue Management
class library {
  node *head;

public:
  library();
  void add_book(int id, string t, string a, bool status); // a. Add a new book
  void remove_book(int id);                               // b. Remove a book
  void display_available(); // c. Display all available books
  void search(int id);      // d. Search for a book using Book ID
};