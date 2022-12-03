#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

namespace Solution {
unordered_map<int, int> lose = {
    {0, 1},
    {1, 2},
    {2, 0},
};

unordered_map<int, int> wins = {
    {1, 0},
    {0, 2},
    {2, 1},
};

int solve() {
  fstream fileReader("./input.txt");
  string line;

  int result = 0;
  while (getline(fileReader, line)) {
    int opponent = line[0] - 'A', me = line[2] - 'X';
    int gain = 0;
    if (wins[me] == opponent)
      gain = 6;
    else if (lose[me] == opponent)
      gain = 0;
    else
      gain = 3;

    result += gain + me + 1;
  }

  return result;
}

int solve2() {
  fstream fileReader("./input.txt");
  string line;

  int result = 0;
  while (getline(fileReader, line)) {
    int opponent = line[0] - 'A', me = line[2] - 'X';
    bool toLose = me == 0;
    bool toTie = me == 1;
    bool toWin = me == 2;

    int score = 0;
    if (toLose) {
      score = wins[opponent];
    } else if (toTie) {
      score = opponent;
    } else if (toWin) {
      score = lose[opponent];
    }

    result += (me * 3) + score + 1;
  }

  return result;
}
}  // namespace Solution

int main() {
  cout << Solution::solve2();
}
