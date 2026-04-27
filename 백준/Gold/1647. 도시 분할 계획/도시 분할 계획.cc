#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m;
vector<tuple<int, int, int>> edge;
int parent[100010];
int level[100010];

int find(int x) {
    if (x == parent[x]) {
        return x;
    }

    return parent[x] = find(parent[x]);
}

void merge(int p, int q) {
    if (level[p] > level[q])
        swap(p, q);

    parent[p] = q;

    if (level[p] == level[q])
        level[q]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    edge.reserve(2 * m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edge.emplace_back(c, a, b);
        edge.emplace_back(c, b, a);
    }

    sort(edge.begin(), edge.end());

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int cnt = 0, ans = 0;
    for (auto& e : edge) {
        if (cnt == n - 2)
            break;
        
        int c = get<0>(e);
        int a = find(get<1>(e));
        int b = find(get<2>(e));

        if (a == b) {
            continue;
        }

        merge(a, b);
        cnt++;
        ans += c;

    }

    cout << ans;
}