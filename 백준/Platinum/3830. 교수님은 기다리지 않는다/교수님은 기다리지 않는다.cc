#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int n, m;
int parent[100010];
ll dist[100010];

int find(int u) {
    if (parent[u] == u) {
        return u;
    }

    int p = find(parent[u]);

    dist[u] += dist[parent[u]];
    return parent[u] = p;
}

void merge(int u, int v, int w) {
    int ru = find(u);
    int rv = find(v);

    if (ru == rv) {
        return;
    }

    dist[rv] = dist[u] - dist[v] + w;
    parent[rv] = ru;
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            dist[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            char type;
            int a, b, w;

            cin >> type >> a >> b;

            if (type == '!') {
                cin >> w;

                merge(a, b, w);
            } else {
                if (find(a) != find(b)) {
                    cout << "UNKNOWN" << '\n';
                } else {
                    cout << dist[b] - dist[a] << '\n';
                }
            }
        }
    }
}