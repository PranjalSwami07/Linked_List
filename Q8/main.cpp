#include "post.h"

int main() {
  post_system feed;

  cout << "--- Adding Posts ---" << endl;
  feed.add_post(1, "Hello world! My first post.", 10.00);
  feed.add_post(2, "Having coffee at my favorite cafe.", 10.30);
  feed.add_post(3, "Heading home now!", 11.15);
  feed.add_post(4, "Late night update!",
                10.45); // Inserted in middle based on timestamp

  // Display feed
  feed.display_newest_to_oldest();

  // Searching post
  feed.search(2);

  // Deleting post
  feed.delete_post(1);

  // Displaying updated feed
  feed.display_newest_to_oldest();

  return 0;
}