#include <iostream>
#include <set>
#include <map>

using namespace std;

int n, m;
map<string, set<string>> team;
map<string, string> mem;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int cnt; string t;
        cin >> t >> cnt;

        for (int j = 0; j < cnt; j++) {
            string k; cin >> k;
            team[t].insert(k);
            mem[k] = t;
        }
    }

    for (int i = 0; i < m; i++) {
        int ord; string s;
        cin >> s >> ord;

        if (ord) {
            cout << mem[s] << '\n';
        }
        else {
            for (const string& x : team[s]) {
                cout << x << '\n';
            }
        };
    }
}