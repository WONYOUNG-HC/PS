#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> match;
vector<bool> vis;

bool DFS(int x) {
    if (vis[x])
        return false;
    vis[x] = true;

    for (int y : graph[x]) {
        if (match[y] == -1 || DFS(match[y])) {
            match[y] = x;
            return true;
        }
    }

    return false;
}

int MaxMatching() {
    match.resize(m + 1, -1);
    vis.resize(n + 1);

    int ret = 0;
    for (int i = 1; i <= n; i++) {
        fill(vis.begin(), vis.end(), false);

        if (DFS(i)) ret++;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    graph.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        int k; cin >> k;

        for (int j = 0; j < k; j++) {
            int s; cin >> s;
            graph[i].push_back(s);
        }
    }

    cout << MaxMatching();
}