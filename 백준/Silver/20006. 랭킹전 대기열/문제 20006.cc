#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int p, m;
vector<vector<pair<int, string>>> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> p >> m;
  for (int i = 0; i < p; i++) {
    int a;
    string b;
    cin >> a >> b;

    bool flag = false;
    for (int j = 0; j < v.size(); j++) {
      if (v[j].size() < m && abs(v[j].front().first - a) <= 10) {
        v[j].emplace_back(a, b);
        flag = true;
        break;
      }
    }

    if (!flag) {
      v.push_back(vector<pair<int, string>>{{a, b}});
    }
  }

  for (auto& x : v) {
    cout << (x.size() == m ? "Started!" : "Waiting!") << '\n';

    sort(x.begin(), x.end(),
         [](const pair<int, string>& left, const pair<int, string>& right)
             -> bool { return left.second < right.second; });

    for (auto& y : x) {
      cout << y.first << ' ' << y.second << '\n';
    }
  }
}