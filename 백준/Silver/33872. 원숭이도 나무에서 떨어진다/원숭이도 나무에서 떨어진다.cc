#include <iostream>
#include <vector>

using namespace std;

int n, h;
int s, e;
int banana[30];
int mae[30];
vector<int> graph[30];
bool vis1[30];
bool vis2[30];
int ans = -1;

void f(int node, int profit, int cost) {
    if (cost == 0) {
        if (node == e) {
            ans = max(ans, profit);
        }

        return;
    }

    for (int next : graph[node]) {
        if (!mae[next]) {
            if (!vis1[next]) {
                vis1[next] = true;

                f(next, profit + banana[next], cost - 1);

                vis1[next] = false;
            } else if (!vis2[next]) {
                vis2[next] = true;

                f(next, profit, cost - 1);

                vis2[next] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> h;
    cin >> s >> e;

    for (int i = 1; i <= n; i++) {
        cin >> banana[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> mae[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;

        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vis1[s] = true;

    f(s, banana[s], h);

    cout << ans;
}