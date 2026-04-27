#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

int n, m;
vector<int> adj[20010];
int dist[20010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    fill_n(dist, 20010, INF);

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
            if (dist[next] < INF)
                continue;

            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }

    int node = 1, cnt = 1;
    for (int i = 2; i <= n; i++) {
        if (dist[i] > dist[node]) {
            node = i;
            cnt = 1;
        }
        else if (dist[i] == dist[node]) {
            cnt++;
        }
    }
    
    cout << node << ' ' << dist[node] << ' ' << cnt;
}