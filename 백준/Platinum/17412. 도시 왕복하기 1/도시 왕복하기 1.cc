#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, p;
int capacity[410][410];
int flow[410][410];
int parent[410];

bool bfs() {
    fill(parent, parent + 401, -1);
    queue<int> q;
    q.emplace(1);

    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (int i = 1; i <= n; i++) {
            if (capacity[node][i] - flow[node][i] > 0 && parent[i] < 0) {
                q.push(i);
                parent[i] = node;

                if (i == 2)
                    return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> p;
    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        capacity[a][b] = 1;
    }

    int ans = 0;
    while (bfs()) {
        int node = 2;

        while (node != 1) {
            flow[parent[node]][node] += 1;
            flow[node][parent[node]] -= 1;
            node = parent[node];
        }

        ans++;
    }

    cout << ans;
}