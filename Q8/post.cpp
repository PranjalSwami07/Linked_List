#include "post.h"

// Constructor initializing pointers
post_system::post_system() {
  head = NULL;
  tail = NULL;
}

// 1. Add a new post in sorted order by timestamp (Newest at front / highest
// timestamp first)
void post_system::add_post(int id, string text, float time) {
  node *nn = new node;
  if (!nn)
    return;

  nn->post_id = id;
  nn->content = text;
  nn->timestamp = time;
  nn->next = NULL;
  nn->prev = NULL;

  // Case 1: Empty list
  if (!head) {
    head = nn;
    tail = nn;
    cout << "Post " << id << " added successfully!" << endl;
    return;
  }

  // Case 2: Insert at the beginning (Newest post with highest timestamp)
  if (time >= head->timestamp) {
    nn->next = head;
    head->prev = nn;
    head = nn;
    cout << "Post " << id << " added successfully!" << endl;
    return;
  }

  // Case 3: Insert in middle or at the end based on timestamp
  node *ptr = head;
  while (ptr->next && ptr->next->timestamp > time) {
    ptr = ptr->next;
  }

  nn->next = ptr->next;
  nn->prev = ptr;

  if (ptr->next) {
    ptr->next->prev = nn;
  } else {
    tail = nn; // Inserted at the end
  }
  ptr->next = nn;

  cout << "Post " << id << " added successfully!" << endl;
}

// 2. Delete a post by Post ID
void post_system::delete_post(int id) {
  cout << "----------------- Deleting Post -----------------" << endl;
  node *ptr = head;

  while (ptr) {
    if (ptr->post_id == id) {
      // If post is the only node
      if (ptr == head && ptr == tail) {
        head = NULL;
        tail = NULL;
      }
      // If post is head node
      else if (ptr == head) {
        head = head->next;
        head->prev = NULL;
      }
      // If post is tail node
      else if (ptr == tail) {
        tail = tail->prev;
        tail->next = NULL;
      }
      // If post is in middle
      else {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
      }

      delete ptr; // Free memory
      cout << "Post ID " << id << " deleted successfully!" << endl;
      return;
    }
    ptr = ptr->next;
  }
  cout << "Post ID " << id << " not found!" << endl;
}

// 3. Search a post by ID
void post_system::search(int id) {
  cout << "----------------- Searching Post -----------------" << endl;
  node *ptr = head;

  while (ptr) {
    if (ptr->post_id == id) {
      cout << "Post Found!" << endl;
      cout << "Post ID   : " << ptr->post_id << endl;
      cout << "Content   : " << ptr->content << endl;
      cout << "Timestamp : " << ptr->timestamp << endl;
      return;
    }
    ptr = ptr->next;
  }
  cout << "Post ID " << id << " not found!" << endl;
}

// 4. Display feed from newest to oldest
void post_system::display_newest_to_oldest() {
  node *ptr = head; // head contains newest posts (descending timestamp)
  cout << "\n----------------- Social Media Feed (Newest to Oldest) "
          "-----------------"
       << endl;
  if (!head) {
    cout << "No posts available!" << endl;
    return;
  }
  while (ptr) {
    cout << "[" << ptr->timestamp << "] Post #" << ptr->post_id << ": "
         << ptr->content << endl;
    ptr = ptr->next;
  }
  cout << "--------------------------------------------------------------------"
          "----"
       << endl;
}