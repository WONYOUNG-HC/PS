#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF (1e9 + 7)
#define COST first
#define NODE second

using namespace std;

// solve by dijkstra
vector<vector<pair<int, int>>> graph;

int Dijkstra(int n, int start, int end);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].emplace_back(c, b);
        graph[b].emplace_back(c, a);
    }

    int start, end;
    cin >> start >> end;

    cout << Dijkstra(n, start, end);
}

int Dijkstra(int n, int start, int end) {
    vector<int> weight(n + 1, 0);
    priority_queue<pair<int, int>> pq;
    pq.emplace(INF, start);

    while (!pq.empty()) {
        int cost = pq.top().COST;
        int node = pq.top().NODE;
        pq.pop();

        if (weight[node] > cost)
            continue;

        for (pair<int, int>& pr : graph[node]) {
            int next_cost = pr.COST;
            int next_node = pr.NODE;

            if (weight[next_node] < min(cost, next_cost)) {
                weight[next_node] = min(cost, next_cost);
                pq.emplace(weight[next_node], next_node);
            }
        }
    }

    return weight[end];
}