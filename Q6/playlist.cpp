#include "playlist.h"

// Constructor initializing head pointer to NULL
playlist::playlist() { head = NULL; }

// a. Add songs to the end of the playlist
void playlist::add_song(int id, string t, string a, float d) {
  node *nn = new node;
  if (!nn)
    return;

  nn->song_id = id;
  nn->title = t;
  nn->artist = a;
  nn->duration = d;
  nn->next = NULL;

  // If playlist is empty
  if (!head) {
    head = nn;
    cout << "Song '" << t << "' added to playlist!" << endl;
    return;
  }

  // Traverse to the end and insert
  node *ptr = head;
  while (ptr->next) {
    ptr = ptr->next;
  }
  ptr->next = nn;
  cout << "Song '" << t << "' added to playlist!" << endl;
}

// b. Remove songs by Song ID
void playlist::remove_song(int id) {
  cout << "----------------- Removing Song -----------------" << endl;
  node *ptr = head;
  node *pptr = NULL;

  while (ptr) {
    if (ptr->song_id == id) {
      if (pptr) {
        pptr->next = ptr->next; // Node is in middle or end
      } else {
        head = ptr->next; // Node is head
      }
      cout << "Removed Song: " << ptr->title << " by " << ptr->artist << endl;
      delete ptr; // Free memory
      return;
    }
    pptr = ptr;
    ptr = ptr->next;
  }
  cout << "Song ID " << id << " not found in playlist!" << endl;
}

// c. Display the entire playlist
void playlist::display() {
  node *ptr = head;
  cout << "\n----------------- Entire Playlist -----------------" << endl;
  if (!head) {
    cout << "Playlist is empty!" << endl;
    return;
  }
  while (ptr) {
    cout << "Song ID  : " << ptr->song_id << endl;
    cout << "Title    : " << ptr->title << endl;
    cout << "Artist   : " << ptr->artist << endl;
    cout << "Duration : " << ptr->duration << " mins" << endl;
    cout << "---------------------------------------------------" << endl;
    ptr = ptr->next;
  }
}

// d. Play specific song by Song ID
void playlist::play_song(int id) {
  cout << "----------------- Playing Song -----------------" << endl;
  node *ptr = head;
  while (ptr) {
    if (ptr->song_id == id) {
      cout << "Playing: " << ptr->title << " - " << ptr->artist << " ["
           << ptr->duration << " mins]" << endl;
      return;
    }
    ptr = ptr->next;
  }
  cout << "Cannot play! Song ID " << id << " not found in playlist." << endl;
}