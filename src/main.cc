#include "ezOptionParser.h"
#include "smith_waterman.h"

int main(int argc, char *argv[]) {
  ez::OptionParser option;
  option.overview = "sw: Local alignment algorithm of two sequences.";
  option.add("seq1", true, 1, "Sequence 1", ez::EZ_TEXT);
  option.add("seq2", true, 1, "Sequence 2", ez::EZ_TEXT);
  option.add("-m,--match", false, 1, "Set match score", ez::EZ_INT32, "2", "0", "");
  option.add("-M,--mismatch", false, 1, "Set mismatch penalty", ez::EZ_INT32, "1", "0", "");
  if (!option.parse(argc, argv)) {
    return -1;
  }
  int match=2, mismatch=1;
  std::string seq1="", seq2="";
  if (option.get("-m").isSet) {option.get("-m").get(match);}
  if (option.get("-M").isSet) {option.get("-M").get(mismatch);}
  if (option.get("seq1").isSet) {option.get("seq1").get(seq1);}
  if (option.get("seq2").isSet) {option.get("seq2").get(seq2);}

  sw::SmithWaterman smith_waterman(seq1, seq2, match, mismatch);
  smith_waterman.run();
  smith_waterman.print_alignment();
  return 0;
}
