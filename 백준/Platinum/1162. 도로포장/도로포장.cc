#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

#define INF 1e18

using namespace std;

int n, m, k;
vector<vector<pair<int, long long>>> graph;

long long Dijkstra();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    graph.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >>c;

        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    cout << Dijkstra();
}

long long Dijkstra() {
    vector<vector<long long>> dist(n + 1, vector<long long>(k + 1, INF));
    dist[1][0] = 0;

    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int ,int>>, greater<>> pq;
    pq.emplace(0, 1, 0);

    while (!pq.empty()) {
        long long cost = get<0>(pq.top());
        int node = get<1>(pq.top());
        int pave = get<2>(pq.top());
        pq.pop();

        if (cost > dist[node][pave])
            continue;

        for (pair<int, long long>& pr : graph[node]) {
            int next_node = pr.first;
            long long next_cost = pr.second;

            if (pave < k && dist[next_node][pave + 1] > cost) {
                dist[next_node][pave + 1] = cost;
                pq.emplace(dist[next_node][pave + 1], next_node, pave + 1);
            }

            if (dist[next_node][pave] > cost + next_cost) {
                dist[next_node][pave] = cost + next_cost;
                pq.emplace(dist[next_node][pave], next_node, pave);
            }
        }
    }

    return *min_element(dist[n].begin(), dist[n].end());
}