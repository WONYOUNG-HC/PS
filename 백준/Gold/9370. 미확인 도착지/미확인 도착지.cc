#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, m, t, s, g, h;
vector<pii> adj[2010];
int dist[2010], target[110];
bool pass[2010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        fill_n(adj, n + 10, vector<pii>());
        fill_n(dist, n + 10, 1e9);
        fill_n(pass, n + 10, false);
        if (g > h)
            swap(g, h);

        for (int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            adj[a].emplace_back(d, b);
            adj[b].emplace_back(d, a);
        }

        for (int i = 0; i < t; i++)
            cin >> target[i];

        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.emplace(0, s);
        dist[s] = 0;

        while (!pq.empty()) {
            pii x = pq.top();
            pq.pop();

            if (dist[x.second] > x.first)
                continue;
            
            for (pii y : adj[x.second]) {
                if (dist[y.second] >= x.first + y.first) {
                    if (dist[y.second] > x.first + y.first) {
                        dist[y.second] = x.first + y.first;
                        pq.emplace(dist[y.second], y.second);
                        pass[y.second] = false;
                    }

                    if (pass[x.second])
                        pass[y.second] = true;
                    else if (min(y.second, x.second) == g && max(y.second, x.second) == h)
                        pass[y.second] = true;
                }
            }
        }

        sort(target, target + t);
        bool flag = false;
        for (int i = 0; i < t; i++) {
            if (dist[target[i]] < 1e9 && pass[target[i]]) {
                cout << target[i] << ' ';
                flag = true;
            }
        }
        flag && (cout << '\n');
    }
}