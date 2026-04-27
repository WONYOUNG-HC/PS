#include <iostream>
#include <map>
#include <algorithm>

#define N 200022

using namespace std;

int parent[N], level[N], net[N];

int Find(int x) {
    if (x == parent[x])
        return x;

    return parent[x] = Find(parent[x]);
}

int Merge(int p, int q) {
    p = Find(p);
    q = Find(q);

    if (p == q)
        return net[p];

    if (level[q] > level[p])
        swap(p, q);

    parent[q] = p;

    if (level[p] == level[q])
        level[p]++;

    net[p] += net[q];

    return net[p];
}

void solve() {
    int f; cin >> f;

    for (int i = 1; i < 2 * f + 10; i++)
        parent[i] = i;
    fill_n(level, 2 * f + 10, 1);
    fill_n(net, 2 * f + 10, 1);

    map<string, int> m;
    int id = 0;

    for (int i = 0; i < f; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        int v1, v2;

        auto it = m.find(s1);
        if (it == m.end())
            v1 = id, m[s1] = id++;
        else
            v1 = m[s1];

        it = m.find(s2);
        if (it == m.end())
            v2 = id, m[s2] = id++;
        else
            v2 = m[s2];

        cout << Merge(v1, v2) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) solve();
}