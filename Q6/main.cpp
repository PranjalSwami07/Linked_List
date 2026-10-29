#include "playlist.h"

int main() {
  playlist my_playlist;

  cout << "--- Adding Songs to Playlist ---" << endl;
  my_playlist.add_song(1, "Shape of You", "Ed Sheeran", 3.53);
  my_playlist.add_song(2, "Blinding Lights", "The Weeknd", 3.20);
  my_playlist.add_song(3, "Levitating", "Dua Lipa", 3.23);

  // Displaying entire playlist
  my_playlist.display();

  // Playing specific songs
  my_playlist.play_song(2);
  my_playlist.play_song(5); // Non-existent song

  // Removing a song
  my_playlist.remove_song(1);

  // Displaying playlist after deletion
  my_playlist.display();

  return 0;
}
