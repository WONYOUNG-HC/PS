#include <iostream>
#include <map>
#include <set>

using namespace std;

int n, c;
map<int, pair<int, int>> m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    if (m.find(a) == m.end()) {
      m[a] = {1, i};
    } else {
      m[a].first++;
    }
  }

  set<pair<int, pair<int, int>>> s;
  for (auto it = m.begin(); it != m.end(); it++) {
    s.insert({-it->second.first, {it->second.second, it->first}});
  }

  for (auto el : s) {
    for (int i = 0; i < -el.first; i++) {
      cout << el.second.second << ' ';
    }
  }
}