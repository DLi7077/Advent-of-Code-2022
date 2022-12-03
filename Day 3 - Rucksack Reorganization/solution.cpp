#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace Solution {

vector<char> intersection(string &a, string &b) {
  vector<char> result;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int aPtr = 0, bPtr = 0;
  while (aPtr < a.size() && bPtr < b.size()) {
    if (a[aPtr] == b[bPtr]) {
      if (result.size() && a[aPtr] == result.back()) {
        aPtr++, bPtr++;
        continue;
      }
      result.push_back(a[aPtr]);
      aPtr++, bPtr++;
      continue;
    }
    if (a[aPtr] < b[bPtr]) {
      aPtr++;
    } else {
      bPtr++;
    }
  }

  return result;
}

int solve() {
  fstream fileReader("./input.txt");
  string line;

  vector<int> lowerCases(26, 0);
  vector<int> upperCases(26, 0);

  int result = 0;
  while (fileReader >> line) {
    int n = line.size();
    string a = line.substr(0, n / 2);
    string b = line.substr(n / 2, n / 2);

    vector<char> commons = intersection(a, b);

    for (char &c : commons) {
      if (islower(c)) {
        lowerCases[c - 'a']++;
      } else if (isupper(c)) {
        upperCases[c - 'A']++;
      }
    }
  }

  for (int i = 0; i < lowerCases.size(); i++) {
    if (lowerCases[i] != 0) {
      result += (i + 1) * lowerCases[i];
    }
  }
  for (int i = 0; i < upperCases.size(); i++) {
    if (upperCases[i] != 0) {
      result += (i + 27) * upperCases[i];
    }
  }
  return result;
}

int solve2() {
  fstream fileReader("./input.txt");
  string lineA, lineB, lineC;

  vector<int> lowerCases(26, 0);
  vector<int> upperCases(26, 0);

  int result = 0;
  while (fileReader >> lineA >> lineB >> lineC) {
    vector<char> firstIntersect = intersection(lineA, lineB);
    string commonAB(firstIntersect.begin(), firstIntersect.end());
    vector<char> commons = intersection(commonAB, lineC);

    for (char &c : commons) {
      if (islower(c)) {
        lowerCases[c - 'a']++;
      } else if (isupper(c)) {
        upperCases[c - 'A']++;
      }
    }
  }

  for (int i = 0; i < lowerCases.size(); i++) {
    if (lowerCases[i] != 0) {
      result += (i + 1) * lowerCases[i];
    }
  }
  for (int i = 0; i < upperCases.size(); i++) {
    if (upperCases[i] != 0) {
      result += (i + 27) * upperCases[i];
    }
  }
  return result;
}
}  // namespace Solution

int main() {
  cout << Solution::solve() << "\n";
  cout << Solution::solve2() << "\n";
}