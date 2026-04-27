#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
set<set<int>> ans;

void f(int cnt, int cur, set<int>& s) {
    if (cnt == m) {
        ans.insert(s);
        return;
    }

    for (int i = cur; i < n; i++) {
        s.insert(arr[i]);
        f(cnt + 1, i + 1, s);
        s.erase(arr[i]);
    }
}

int main() {
   cin >> n >> m;
   for (int i = 0; i < n; i++)
       cin >> arr[i];

   set<int> s;
   f(0, 0, s);

   for (auto& x : ans) {
       for (auto& y : x) {
         cout << y << ' ';
       }
       cout << '\n';
   }
}