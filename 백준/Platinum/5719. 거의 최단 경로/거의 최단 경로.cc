#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

int n, m, s, d;
int graph[510][510];
int dist[510];
vector<int> pre[510];

void del(int node) {
    if (node == s)
        return;

    for (int prev : pre[node]) {
        if (graph[prev][node] < INF) {
            graph[prev][node] = INF;
            del(prev);
        }
    }
}

int solve() {
    cin >> s >> d;

    fill_n(&graph[0][0], 510 * 510, INF);
    fill_n(dist, 510, INF);
    for (int i = 0; i < n; i++) pre[i].clear();

    for (int i = 0; i < m; i++) {
        int u, v, p;
        cin >> u >> v >> p;

        graph[u][v] = p;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, s);
    dist[s] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node] < cost)
            continue;

        for (int i = 0; i < n; i++) {
            if (dist[i] > graph[node][i] + cost) {
                dist[i] = graph[node][i] + cost;
                pq.emplace(dist[i], i);
                pre[i].clear();
                pre[i].push_back(node);
            }
            else if (dist[i] != INF && dist[i] == graph[node][i] + cost) {
                pre[i].push_back(node);
            }
        }
    }

    //if (dist[d] == INF)
        //return -1;

    del(d);

    fill_n(dist, 510, INF);

    pq.emplace(0, s);
    dist[s] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node] < cost)
            continue;

        for (int i = 0; i < n; i++) {
            if (dist[i] > graph[node][i] + cost) {
                dist[i] = graph[node][i] + cost;
                pq.emplace(dist[i], i);
            }
        }
    }

    return dist[d] == INF ? -1 : dist[d];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    while (n != 0 && m != 0) {
        cout << solve() << '\n';
        cin >> n >> m;
    }
}