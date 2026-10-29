/* Consider the playlist in a music player. Implement a playlist feature in
music player application using singly linked list. Each song in the playlist is
represented as a node in the linked list. Each node contains information about
the song (such as title or artist or duration, etc.).The playlist should allow
users to: a. Add songs b. Remove songs c. Display the entire playlist d. Play
specific song*/

#include <iostream>
#include <string>

using namespace std;

// Structure for a Song Node
struct node {
  int song_id;
  string title;
  string artist;
  float duration;
  node *next;
};

// Class definition for Music Player Playlist Management
class playlist {
  node *head;

public:
  playlist();
  void add_song(int id, string t, string a, float d); // a. Add song
  void remove_song(int id);                           // b. Remove song
  void display();         // c. Display entire playlist
  void play_song(int id); // d. Play specific song
};