#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int SOURCE = 0;
const int TARGET = 1000;
const int WORK = 500;

int n, m;
vector<int> graph[1010];
int cap[1010][1010];
int flow[1010][1010];
int cost[1010][1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int cnt;

        cin >> cnt;

        for (int j = 0; j < cnt; j++) {
            int w, c;

            cin >> w >> c;

            w += WORK;

            cap[i][w] = 1;

            graph[i].push_back(w);
            cost[i][w] = c;

            graph[w].push_back(i);
            cost[w][i] = -c;
        }
    }

    for (int i = 1; i <= n; i++) {
        cap[SOURCE][i] = 1;
        graph[SOURCE].push_back(i);
    }

    for (int i = 1; i <= m; i++) {
        cap[WORK + i][TARGET] = 1;
        graph[WORK + i].push_back(TARGET);
    }

    //
    //
    //

    int cnt = 0;
    int res = 0;

    while (true) {
        int prev[1010];
        int dist[1010];
        bool inq[1010] = {0, };
        queue<int> q;

        fill(prev, prev + 1010, -1);
        fill(dist, dist + 1010, 1e9);

        dist[SOURCE] = 0;
        inq[SOURCE] = true;
        q.push(SOURCE);

        while (!q.empty()) {
            int cur = q.front();

            q.pop();
            inq[cur] = false;

            for (int next : graph[cur]) {
                if (cap[cur][next] - flow[cur][next] > 0 && dist[next] > dist[cur] + cost[cur][next]) {
                    dist[next] = dist[cur] + cost[cur][next];
                    prev[next] = cur;

                    if (!inq[next]) {
                        inq[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        if (prev[TARGET] == -1) {
            break;
        }

        int node = TARGET;

        while (node != SOURCE) {
            flow[prev[node]][node] += 1;
            flow[node][prev[node]] -= 1;

            node = prev[node];
        }

        res += dist[TARGET];
        cnt += 1;
    }

    cout << cnt << '\n' << res;
}