#include <iostream>
#include <vector>

using namespace std;

vector<int> root;
vector<int> node_rank;

int find(int node) {
    if (node == root[node])
        return node;

    return root[node] = find(root[node]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return false;

    if (node_rank[a] < node_rank[b])
        root[a] = b;
    else
        root[b] = a;

    if (node_rank[a] == node_rank[b])
        node_rank[a]++;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    root.resize(n);
    node_rank.resize(n);
    for (int i = 0; i < n; i++) {
        root[i] = i;
        node_rank[i] = 1;
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        if (!merge(a, b)) {
            cout << i;
            return 0;
        }
    }

    cout << 0;

    return 0;
}