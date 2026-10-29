#include "browser.h"

int main() {
  browser b;

  cout << "-----Opening tabs-----" << endl;
  b.add_tab("google.com");
  b.add_tab("github.com");
  b.add_tab("youtube.com");

  b.display();

  cout << "------Navigating Backward -------" << endl;
  b.move_backward();
  b.move_backward();
  b.move_backward();

  b.display();

  cout << "----------Searching Tabs------------" << endl;
  b.search("github.com");

  return 0;
}