#include "railway.h"

int main() {
  railway r;

  cout << "--- Adding Passengers to Waiting List ---" << endl;
  r.add_passenger(101, "Rahul Sharma", 28);
  r.add_passenger(102, "Sneha Patil", 24);
  r.add_passenger(103, "Amit Verma", 45);

  // Displaying the list
  r.display();

  // Confirming ticket (Deletes from front)
  r.delete_front();

  // Displaying list after confirmation
  r.display();

  // Searching passenger
  r.search(102);
  r.search(101); // Was deleted as ticket got confirmed

  return 0;
}