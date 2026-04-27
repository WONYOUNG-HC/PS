#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int node);

int n, m;
vector<vector<int>> graph;
vector<pair<int, int>> child;

bool Pred(const pair<int, int>& left, const pair<int, int>& right) {
    if (left.first != right.first)
        return left.first > right.first;
    return left.second < right.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    graph.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    child.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        child[i].second = i;
        bfs(i);
    }

    sort(child.begin(), child.end(), Pred);

    int ans = child[0].first;
    for (int i = 0; i < n; i++) {
        if (ans != child[i].first)
            break;

        cout << child[i].second << ' ';
    }
}

void bfs(int node) {
    queue<int> q;
    vector<bool> visited(n + 1);
    q.push(node);
    visited[node] = true;
    int cnt = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                cnt++;
            }
        }
    }

    child[node].first = cnt;
}