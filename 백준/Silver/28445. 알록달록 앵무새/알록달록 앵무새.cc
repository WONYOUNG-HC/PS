#include <iostream>
#include <set>

using namespace std;

int main() {
    string a[4];
    for (auto& x : a) cin >> x;

    set<pair<string, string>> s;
    for (auto& x : a) for (auto& y : a)
        s.emplace(x, y);

    for (auto& x : s)
        cout << x.first << ' ' << x.second << '\n';
}