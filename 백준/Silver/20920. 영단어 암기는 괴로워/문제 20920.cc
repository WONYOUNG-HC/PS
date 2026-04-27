#include <iostream>
#include <set>
#include <map>

using namespace std;

struct Pred {
    bool operator()(const pair<int, string>& left, const pair<int, string>& right) const {
        if (left.first != right.first)
            return left.first > right.first;

        if (left.second.length() != right.second.length())
            return left.second.length() > right.second.length();

        return left.second < right.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<string, int> wm;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        if (s.length() < m)
            continue;

        wm.find(s) == wm.end() ? wm[s] = 1 : wm[s] += 1;
    }

    set<pair<int, string>, Pred> sm;
    for (auto& it: wm)
        sm.emplace(it.second, it.first);

    for (auto& it : sm)
        cout << it.second << '\n';
}