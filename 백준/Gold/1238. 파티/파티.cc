#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 0x3fffffff

using namespace std;

void Dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& dist);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<pair<int, int>>> graph(n+1);
    for (int i=0; i<m; i++) {
        int start, end, time;
        cin >> start >> end >> time;
        graph[start].emplace_back(time, end);
    }

    vector<int> total(n+1);
    vector<int> dist(n+1, INF);
    Dijkstra(x, graph, dist);
    for (int i=1; i<=n; i++)
        total[i] = dist[i];

    for (int i=1; i<=n; i++) {
        if (i == x)
            continue;

        fill(dist.begin(), dist.end(), INF);
        Dijkstra(i, graph, dist);
        total[i] += dist[x];
    }

    cout << *max_element(total.begin()+1, total.end());
}

void Dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node] < cost)
            continue;

        for (pair<int, int> &next: graph[node]) {
            if (dist[next.second] > next.first + cost) {
                dist[next.second] = next.first + cost;
                pq.emplace(dist[next.second], next.second);
            }
        }
    }
}