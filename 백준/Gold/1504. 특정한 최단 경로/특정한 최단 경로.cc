#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 100000000;
vector<vector<pair<int, int>>> graph;

int Dijkstra(int n, int start, int end);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;

    graph.resize(n+1);
    int a, b, c;
    for (int i=0; i<e; i++) {
        cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
        graph[b].emplace_back(c, a);
    }

    int v1, v2;
    cin >> v1 >> v2;

    int ans1 = Dijkstra(n, 1, v1) + Dijkstra(n, v1, v2) + Dijkstra(n, v2, n);
    int ans2 = Dijkstra(n, 1, v2) + Dijkstra(n, v2, v1) + Dijkstra(n, v1, n);
    int ans = min(ans1, ans2);

    cout << (ans >= INF ? -1 : ans);
}

int Dijkstra(int n, int start, int end) {
    int distance[n+1];
    fill_n(distance, n+1, INF);
    distance[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (distance[node] < cost)
            continue;

        for (pair<int, int>& next : graph[node]) {
            if (distance[next.second] > cost + next.first) {
                distance[next.second] = cost + next.first;
                pq.emplace(distance[next.second], next.second);
            }
        }
    }

    return distance[end];
}