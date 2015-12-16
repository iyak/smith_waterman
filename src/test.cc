#include <iostream>
#include "smith_waterman.h"

int main() {
  using namespace std;
  int fail=0;

  /* test 1 */
  sw::SmithWaterman smith_waterman("ACGT", "ACGT", 1, 1);
  int score;
  if ((score = smith_waterman.run()) != 4) {
    cout << "ACGT - ACGT: " << score << " (correct: 4)" << endl;
    ++ fail;
  }

  cout << fail << " test failed." << endl;
  if (0 < fail) {return 1;}
  return 0;
}
