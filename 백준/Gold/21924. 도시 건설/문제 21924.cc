#include <iostream>
#include <tuple>
#include <algorithm>

#define ll long long
#define ti tuple<int, int, int>

using namespace std;

int n, m;
ll tot;
ti edge[500010];
int root[100010], level[100010];

int find(int x) {
    if (x == root[x])
        return x;
    return root[x] = find(root[x]);
}

void merge(int x, int y) {
    if (level[x] < level[y])
        swap(x, y);

    root[y] = x;

    if (level[x] == level[y])
        level[x]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edge[i] = {c, a, b};
        tot += c;
    }

    sort(edge, edge + m);

    for (int i = 1; i <= n; i++)
        root[i] = i, level[i] = 1;

    int cnt = 0; ll ans = 0;
    for (int i = 0; i < m; i++) {
        int c = get<0>(edge[i]);
        int a = find(get<1>(edge[i]));
        int b = find(get<2>(edge[i]));

        if (a == b)
            continue;

        merge(a, b);
        ans += c, cnt++;

        if (cnt == n - 1)
            break;
    }

    cout << (cnt == n - 1 ? tot - ans : -1);
}