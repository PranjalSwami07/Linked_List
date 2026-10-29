#include "coach.h"

int main() {
  coach train;

  cout << "--- Attaching Coaches ---" << endl;
  train.add_rear(101, "Sleeper");
  train.add_rear(102, "Sleeper");
  train.add_front(201, "AC First Class");   // Added at front (Near Engine)
  train.add_at_position(301, "General", 2); // Added at position 2

  // Display coaches from last coach to engine
  train.display_rear_to_front();

  cout << "\n--- Searching Coach ---" << endl;
  train.search(102);
  train.search(999);

  cout << "\n--- Removing Coach ---" << endl;
  train.remove(301);

  // Display after removing a coach
  train.display_rear_to_front();

  return 0;
}