#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int s, e = 201;
int capa[210][210];
int flow[210][210];
int parent[210];
vector<int> adj[210];

int bfs() {
    queue<int> q;
    int f = 1e9;

    fill_n(parent, 210, -1);

    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
            if (capa[cur][next] - flow[cur][next] > 0 && parent[next] < 0) {
                parent[next] = cur;
                f = min(f, capa[cur][next] - flow[cur][next]);
                q.push(next);

                if (next == e) {
                    return f;
                } 
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> capa[s][i];

        adj[s].push_back(i);
        adj[i].push_back(s);
    }

    for (int i = 1; i <= m; i++) {
        cin >> capa[100 + i][e];

        adj[100 + i].push_back(e);
        adj[e].push_back(100 + i);
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> capa[j][100 + i];

            adj[j].push_back(100 + i);
            adj[100 + i].push_back(j);
        }
    }

    int ans = 0;
    int f = 0;

    while ((f = bfs()) != -1) {
        int cur = e;
        
        while (cur != s) {
            flow[parent[cur]][cur] += f;
            flow[cur][parent[cur]] -= f;
            cur = parent[cur];
        }

        ans += f;
    }

    cout << ans;
}