#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Prim(int n, vector<vector<pair<int, int>>>& graph);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n+1);
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b) continue;
        graph[a].emplace_back(c, b);
        graph[b].emplace_back(c, a);
    }

    cout << Prim(n, graph);
}

int Prim(int n, vector<vector<pair<int, int>>>& graph) {
    vector<bool> visited(n+1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (pair<int, int>& pr : graph[1])
        pq.emplace(pr.first, pr.second);
    visited[1] = true;
    int cnt = 1, ans = 0;

    while (cnt != n) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        cnt++;
        ans += cost;
        for (pair<int, int>& next : graph[node]) {
            if (!visited[next.second])
                pq.emplace(next.first, next.second);
        }
    }

    return ans;
}