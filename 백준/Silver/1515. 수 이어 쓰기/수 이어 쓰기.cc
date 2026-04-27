#include <iostream>
#include <queue>

using namespace std;

int main() {
  string str;
  cin >> str;

  queue<char> q;
  for (char c : str) {
    q.push(c);
  }

  int n = 0;
  while (!q.empty()) {
    for (char c : to_string(++n)) {
      if (c == q.front()) {
        q.pop();
      }

      if (q.empty()) {
        break;
      }
    }
  }

  cout << n;
}