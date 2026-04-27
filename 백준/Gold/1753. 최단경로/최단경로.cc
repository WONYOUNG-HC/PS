#include <iostream>
#include <vector>
#include <queue>
#include <deque>

#define INF 100000000

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> dp;

void Dijkstra(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int node, edge, start;
    cin >> node >> edge >> start;

    int u, v, w;
    graph.resize(node+1);
    dp.resize(node+1, INF);
    for (int i=0; i<edge; i++) {
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
    }

    Dijkstra(start);

    for (vector<int>::size_type i=1; i<dp.size(); i++) {
        if (dp[i] == INF)
            cout << "INF \n";
        else
            cout << dp[i] << '\n';
    }
}

void Dijkstra(int start) {
    dp[start] = 0;
    priority_queue<pair<int, int>, deque<pair<int, int>>, greater<>> pq;
    pq.push(make_pair(0, start));

    int cur, cost;
    while (!pq.empty()) {
        cost = pq.top().first;
        cur = pq.top().second;
        pq.pop();

        if (dp[cur] < cost)
            continue;

        for (auto & i : graph[cur]) {
            if (dp[i.second] > cost + i.first) {
                dp[i.second] = cost + i.first;
                pq.push(make_pair(dp[i.second], i.second));
            }
        }
    }
}
