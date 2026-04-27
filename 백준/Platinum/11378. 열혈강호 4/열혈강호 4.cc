#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
int capacity[2010][2010], flow[2010][2010], parent[2010];
int source = 2001, sink = 2002, bridge = 2003;
vector<int> adj[2010];

bool bfs() {
    fill_n(parent, 2010, -1);
    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
            if (capacity[cur][next] - flow[cur][next] > 0 && parent[next] == -1) {
                parent[next] = cur;
                q.push(next);

                if (next == sink)
                    return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    capacity[source][bridge] = k;
    adj[source].push_back(bridge);
    adj[bridge].push_back(source);

    for (int i = 1; i <= n; i++) {
        capacity[source][i] = 1;
        capacity[bridge][i] = k;
        adj[source].push_back(i);
        adj[bridge].push_back(i);
        adj[i].push_back(source);
        adj[i].push_back(bridge);

        int c; cin >> c;
        for (int j = 0; j < c; j++) {
            int w; cin >> w;
            capacity[i][w + 1000] = 1;
            adj[i].push_back(w + 1000);
            adj[w + 1000].push_back(i);
        }
    }

    for (int i = 1; i <= m; i++) {
        capacity[i + 1000][sink] = 1;
        adj[i + 1000].push_back(sink);
        adj[sink].push_back(i + 1000);
    }

    int ans = 0;
    while (bfs()) {
        int node = sink;

        while (node != source) {
            flow[parent[node]][node] += 1;
            flow[node][parent[node]] -= 1;

            node = parent[node];
        }

        ans++;
    }

    cout << ans;
}