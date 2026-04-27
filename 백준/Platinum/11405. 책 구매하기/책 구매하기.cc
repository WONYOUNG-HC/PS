#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int SOURCE = 0;
const int TARGET = 300;
const int OFFSET = 150;
const int INF = 1e9;

int n, m;
vector<int> graph[310];
int cost[310][310];
int cap[310][310];
int flow[310][310];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int a;

        cin >> a;

        graph[SOURCE].push_back(i);
        cap[SOURCE][i] = a;
    }

    for (int i = 1; i <= m; i++) {
        int b;

        cin >> b;

        graph[OFFSET + i].push_back(TARGET);
        cap[OFFSET + i][TARGET] = b;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int c;

            cin >> c;

            graph[j].push_back(OFFSET + i);
            graph[OFFSET + i].push_back(j);

            cap[j][OFFSET + i] = INF;

            cost[j][OFFSET + i] = c;
            cost[OFFSET + i][j] = -c;
        }
    }

    //
    //
    //

    int ans = 0;
    
    while (true) {
        queue<int> q;
        int dist[310];
        int prev[310];
        bool inq[310] = {0, };

        fill(dist, dist + 310, INF);
        fill(prev, prev + 310, -1);

        inq[SOURCE] = true;
        q.push(SOURCE);
        dist[SOURCE] = 0;

        while (!q.empty()) {
            int cur = q.front();
            inq[cur] = false;
            q.pop();

            for (int next : graph[cur]) {
                if (cap[cur][next] - flow[cur][next] > 0 && dist[next] > dist[cur] + cost[cur][next]) {
                    dist[next] = dist[cur] + cost[cur][next];
                    prev[next] = cur;

                    if (!inq[next]) {
                        q.push(next);
                        inq[next] = true;
                    }
                }
            }
        }

        if (prev[TARGET] == -1) {
            break;
        }

        int node = TARGET;
        int f = INF;

        while (node != SOURCE) {
            f = min(f, cap[prev[node]][node] - flow[prev[node]][node]);
            node = prev[node];
        }

        node = TARGET;

        while (node != SOURCE) {
            ans += f * cost[prev[node]][node];

            flow[prev[node]][node] += f;
            flow[node][prev[node]] -= f;

            node = prev[node];
        }
    }

    cout << ans;
}