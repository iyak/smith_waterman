#ifndef SMITH_WATERMAN__SMITH_WATERMAN__H
#define SMITH_WATERMAN__SMITH_WATERMAN__H
#include <string>
#include <vector>
#include <iostream>
namespace sw{class SmithWaterman;}
class sw::SmithWaterman{
  typedef std::string string;
  typedef std::vector<int> VI;
  typedef std::vector<VI> VVI;
  string _seq1, _seq2;
  int _match, _mismatch;
  VVI _sw_table, _trance_back;
 public:
  SmithWaterman(string seq1, string seq2, int match, int mismatch) {
    _match = match;
    _mismatch = mismatch;
    _seq1 = seq1;
    _seq2 = seq2;
    _sw_table.assign(_seq1.size()+1, VI(_seq2.size()+1, 0x80000000/* min int32 */));
    _sw_table[0].assign(_seq2.size()+1, 0);
    for (auto &t: _sw_table) t[0] = 0;
    _trance_back.assign(_seq1.size()+1, VI(_seq2.size()+1, -1)); /* 0:\, 1:-, 2:| */
    for (auto &c: _trance_back[0]) c=2;
    for (auto &c: _trance_back) c[0]=1;
  }
  void run() {
    for (int i = 1; i <= _seq1.size(); ++ i) {
      for (int j = 1; j <= _seq2.size(); ++ j) {
        int score;
        /* match/mismatch */
        if (_seq1[i-1] == _seq2[j-1]) score = _sw_table[i-1][j-1] + _match;
        else score = _sw_table[i-1][j-1] - _mismatch;
        if (_sw_table[i][j] < score) {
          _sw_table[i][j] = score;
          _trance_back[i][j] = 0;
        }
        /* gap1 */
        score = _sw_table[i-1][j] - _mismatch;
        if (_sw_table[i][j] < score) {
          _sw_table[i][j] = score;
          _trance_back[i][j] = 1;
        }
        /* gap2 */
        score = _sw_table[i][j-1] - _mismatch;
        if (_sw_table[i][j] < score) {
          _sw_table[i][j] = score;
          _trance_back[i][j] = 2;
        }
      }
    }
  }
  void print_alignment() {
    string seq1="", seq2="";
    for (int i=_seq1.size(), j=_seq2.size(); 0!=i or 0!=j;) {
      switch (_trance_back[i][j]) {
        case 0:
          seq1 = _seq1[i-1] + seq1;
          seq2 = _seq2[j-1] + seq2;
          -- i; -- j;
          break;
        case 1:
          seq1 = _seq1[i-1] + seq1;
          seq2 = "-" + seq2;
          -- i;
          break;
        case 2:
          seq1 = "-" + seq1;
          seq2 = _seq2[j-1] + seq2;
          -- j;
          break;
        default:
          std::cerr << "fail to trace-back: " << _trance_back[i][j] << "\n";
          return;
      }
    }
    std::cout << seq1 << std::endl << seq2 << std::endl;
  }
};
#endif

