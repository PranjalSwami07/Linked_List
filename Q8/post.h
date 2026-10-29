/* A social media application stores posts in chronological order using a Doubly
Linked List. Implement the following operations:
1. 3. 4. Add a new post. (Insert a post in sorted order according to timestamp.)
2. Delete a post.
Search a post by ID.
Display feed from newest to oldest.*/

#include <iostream>
#include <string>

using namespace std;

// Structure for a Post Node in Doubly Linked List
struct node {
  int post_id;
  string content;
  float timestamp; // Higher float value represents a newer post
  node *next;
  node *prev;
};

// Class definition for Social Media Feed Management
class post_system {
  node *head;
  node *tail;

public:
  post_system();
  void add_post(int id, string text,
                float time);       // 1. Insert in sorted order by timestamp
  void delete_post(int id);        // 2. Delete a post
  void search(int id);             // 3. Search post by ID
  void display_newest_to_oldest(); // 4. Display feed from newest to oldest
};