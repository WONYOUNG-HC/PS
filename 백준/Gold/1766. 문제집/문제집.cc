#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> in_degree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    graph.resize(n + 1);
    in_degree.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        in_degree[b]++;
    }

    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0)
            pq.push(i);
    }

    vector<int> v;
    while (!pq.empty()) {
        int node = pq.top(); pq.pop();
        v.push_back(node);

        for (int next : graph[node]) {
            in_degree[next]--;

            if (in_degree[next] == 0)
                pq.push(next);
        }
    }

    for (int x : v) cout << x << ' ';
}