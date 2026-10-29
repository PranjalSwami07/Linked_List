#include "history.h"

int main() {
  history h(3);

  cout << "-----------Adding editng actions---------" << endl;
  h.add_action(101, "Typed 'hello' ");
  h.add_action(102, "Typed 'World' ");
  h.add_action(103, " Deleted last word");

  h.display();

  cout << "------Adding 4th action------" << endl;
  h.add_action(104, " Pasted from clipboard");

  h.display();

  cout << "------Searching for action------" << endl;
  h.search(103);
  h.search(101);

  return 0;
}