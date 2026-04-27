#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int inf = 1e9;
int n, p;
int capa[810][810];
int flow[810][810];
int parent[810];

bool bfs() {
    fill_n(parent, 801, -1);
    
    queue<int> q;
    q.push(n + 1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= n * 2; i++) {
            if (capa[cur][i] - flow[cur][i] > 0 && parent[i] < 0) {
                parent[i] = cur;
                q.push(i);

                if (i == 2) {
                    return true;
                }
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

        int a_in = a;
        int a_out = a + n;
        int b_in = b;
        int b_out = b + n;

        capa[a_in][a_out] = 1;
        capa[b_in][b_out] = 1; 

        capa[a_out][b_in] = inf;
        capa[b_out][a_in] = inf;
    }

    //
    //
    //

    int ans = 0;

    while (bfs()) {
        int node = 2;

        while (node != n + 1) {
            flow[parent[node]][node] += 1;
            flow[node][parent[node]] -= 1;

            node = parent[node];
        }

        ans += 1;
    }

    cout << ans;
}