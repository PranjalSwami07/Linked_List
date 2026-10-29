#include "library.h"

int main() {
  library lib;

  cout << "--- Adding Books to Catalogue ---" << endl;
  lib.add_book(101, "Data Structures in C++", "Pranjal Swami", true);
  lib.add_book(102, "Operating Systems", "A. Silberschatz", false);
  lib.add_book(103, "Clean Code", "Robert C. Martin", true);

  // Displaying all available books
  lib.display_available();

  // Searching for a book
  lib.search(102);
  lib.search(999); // Non-existent book

  // Removing a book
  lib.remove_book(101);

  // Displaying available books after removal
  lib.display_available();

  return 0;
}