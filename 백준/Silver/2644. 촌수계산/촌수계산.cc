#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Bfs(int n, vector<vector<int>>& graph, int from, int to);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int from, to;
    cin >> from >> to;

    vector<vector<int>> graph(n+1);
    int m;
    cin >> m;

    int a, b;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << Bfs(n, graph, from, to);
}

int Bfs(int n, vector<vector<int>>& graph, int from, int to) {
    vector<bool> visited(n+1, false);
    queue<pair<int, int>> q;
    for (int i : graph[from])
        q.emplace(1, i);

    while (!q.empty()) {
        int cost = q.front().first;
        int node = q.front().second;
        q.pop();

        if (node == to) {
            return cost;
        }

        for (int next : graph[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.emplace(cost + 1, next);
            }
        }
    }

    return -1;
}