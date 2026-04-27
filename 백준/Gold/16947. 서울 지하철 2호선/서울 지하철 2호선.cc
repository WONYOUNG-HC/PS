#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> graph[3010];
vector<int> route;
bool vis[3010];
int dist[3010];

void dfs(int cur) {
    vis[cur] = true;
    route.push_back(cur);

    for (int next : graph[cur]) {
        if (route.size() > 1 && *(route.rbegin() + 1) == next) {
            continue;
        }

        if (!vis[next]) {
            dfs(next);
        } else if (dist[next] == -1) {
            for (auto it = route.rbegin(); it < route.rend(); it++) {
                dist[*it] = 0;

                if (*it == next) {
                    break;
                }
            }
        }
    }

    route.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;

        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //
    //
    //

    fill_n(dist, 3010, -1);

    dfs(1);

    //
    //
    //

    for (int i = 1; i <= n; i++) {
        if (dist[i] == -1) {
            continue;
        }

        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next : graph[cur]) {
                if (dist[next] != -1) {
                    continue;
                }

                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
}