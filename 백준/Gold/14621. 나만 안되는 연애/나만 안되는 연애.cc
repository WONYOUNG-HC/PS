#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, d;

    Edge(int u, int v, int d) : u(u), v(v), d(d) {}

    bool operator<(const Edge &operand) const {
        return d < operand.d;
    }
};

int n, m;
char univ[1010];
vector<Edge> edge;
int parent[1010];
int level[1010];

int find(int x) {
    if (parent[x] == x) {
        return x;
    }

    return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) {
        return false;
    }

    if (level[y] > level[x]) {
        swap(x, y);
    }

    parent[y] = x;

    if (level[x] == level[y]) {
        level[x] += 1;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> univ[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        if (univ[u] == univ[v]) {
            continue;
        }

        edge.emplace_back(u, v, d);
    }

    //
    //
    //

    int cost = 0;
    int count = 0;

    sort(edge.begin(), edge.end());

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        level[i] = 1;
    }

    for (auto e : edge) {
        if (merge(e.u, e.v)) {
            cost += e.d;
            count += 1;
        }
    }

    cout << (count == n - 1 ? cost : -1);
}