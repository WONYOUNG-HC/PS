#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

const ll INF = (ll)1e20;
const int source = 301, sink = 302;
int n, m;
vector<int> adj[310];
ll arr[310];
ll capacity[310][310], flow[310][310];
int parent[310];

ll bfs() {
    fill_n(parent, 310, -1);
    queue<int> q;
    q.push(source);

    ll cut = INF;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int y : adj[x]) {
            if (capacity[x][y] - flow[x][y] > 0 && parent[y] < 0) {
                parent[y] = x;
                q.push(y);
                cut = min(cut, capacity[x][y] - flow[x][y]);

                if (y == sink)
                    return cut;
            }
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        
        adj[i].push_back(sink);
        capacity[i][sink] = INF;
    }
    for (int i = n + 1; i <= n + m; i++) {
        cin >> arr[i];
        
        adj[source].push_back(i);
        capacity[source][i] = arr[i];
    }

    for (int i = n + 1; i <= n + m; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int a; cin >> a;
            
            adj[i].push_back(a);
            adj[a].push_back(i);
            capacity[i][a] = arr[a];
            capacity[a][i] = arr[i];
        }
    }

    ll ans = 0, cut;
    while ((cut = bfs())) {
        int node = sink;

        while (node != source) {
            flow[parent[node]][node] += cut;
            flow[node][parent[node]] -= cut;
            node = parent[node];
        }

        ans += cut;
    }

    cout << ans;
}