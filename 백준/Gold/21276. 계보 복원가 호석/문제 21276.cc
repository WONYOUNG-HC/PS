#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int n, m;
vector<int> adj[1010], nadj[1010];
map<string, int> si;
string is[1010];
int ind[1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    vector<string> v(n);
    for (string& s : v) cin >> s;

    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        si[v[i]] = i;
        is[i] = v[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        string sa, sb;
        cin >> sa >> sb;

        int ia = si[sa], ib = si[sb];
        adj[ib].push_back(ia);
        ind[ia]++;
    }

    vector<int> root;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (ind[i] == 0)
            root.push_back(i), q.push(i);
    }

    cout << root.size() << '\n';
    for (int r : root)
        cout << is[r] << ' ';
    cout << '\n';

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int y : adj[x]) {
            if (--ind[y] == 0) {
                nadj[x].push_back(y);
                q.push(y);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << is[i] << ' ' << nadj[i].size() << ' ';
        
        sort(nadj[i].begin(), nadj[i].end());
        for (int x : nadj[i])
            cout << is[x] << ' ';
        cout << '\n';
    }
}