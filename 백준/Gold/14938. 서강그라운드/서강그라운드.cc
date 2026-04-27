#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 0x3fffffff

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<vector<int>> dist;

void Dijkstra(int n, int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> item(n);
    for (int i=0; i<n; i++)
        cin >> item[i];

    graph.resize(n);
    for (int i=0; i<r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        a--; b--;
        graph[a].emplace_back(l, b);
        graph[b].emplace_back(l, a);
    }

    dist.resize(n);
    for (vector<int>& d : dist) d.resize(n, INF);
    for (int i=0; i<n; i++)
        Dijkstra(n, i);

    int ans = 0;
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=0; j<n; j++) {
            if (dist[i][j] <= m)
                sum += item[j];
        }

        if (ans < sum)
            ans = sum;
    }

    cout << ans;

    return 0;
}

void Dijkstra(int n, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);
    dist[start][start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[start][node] < cost)
            continue;

        for (pair<int, int>& next : graph[node]) {
            if (dist[start][next.second] > cost + next.first) {
                dist[start][next.second] = cost + next.first;
                pq.emplace(cost + next.first, next.second);
            }
        }
    }
}