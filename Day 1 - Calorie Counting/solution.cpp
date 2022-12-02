#include <fstream>
#include <iostream>
#include <queue>
using namespace std;

// https://adventofcode.com/2022/day/1
namespace Solution {
int solve() {
  fstream fileReader("./input.txt");
  string line = "";

  priority_queue<int, vector<int>, greater<int>> minHeap;

  int calories = 0;

  while (getline(fileReader, line)) {
    if (line.size() == 0) {
      minHeap.push(calories);
      calories = 0;

      if (minHeap.size() > 3) minHeap.pop();
    } else {
      calories += stoi(line);
    }
  }

  // handle last group
  minHeap.push(calories);
  calories = 0;

  if (minHeap.size() > 3) minHeap.pop();

  int total = 0;
  while (minHeap.size()) {
    total += minHeap.top();
    minHeap.pop();
  }

  return total;
}
};  // namespace Solution

int main() {
  cout << Solution::solve();
}