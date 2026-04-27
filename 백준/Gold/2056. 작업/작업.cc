#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> in_degree;
vector<int> work;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    graph.resize(n + 1);
    in_degree.resize(n + 1);
    work.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        work[i] = t;

        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int c; cin >> c;
            graph[c].push_back(i);
            in_degree[i]++;
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 1; i <= n; i++)
        if (in_degree[i] == 0) pq.emplace(work[i], i);

    int cur = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        cur = cost;

        for (int next : graph[node]) {
            in_degree[next]--;

            if (in_degree[next] == 0)
                pq.emplace(cur + work[next], next);
        }
    }

    cout << cur;
}