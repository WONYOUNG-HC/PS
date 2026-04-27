#include <iostream>
#include <vector>
#include <tuple>

#define INF 1e9

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        int n, m, w;
        cin >> n >> m >> w;

        vector<tuple<int, int, int>> edge(m * 2 + w);
        for (int i = 0; i < m * 2;) {
            int s, e, t;
            cin >> s >> e >> t;
            edge[i++] = {s, e, t};
            edge[i++] = {e, s, t};
        }
        for (int i = m * 2; i < m * 2 + w; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            edge[i] = {s, e, -t};
        }

        vector<int> dist(n + 1, INF);
        dist[1] = 0;

        for (int i = 0; i < n - 1; i++) {
            for (auto& tp : edge) {
                int s = get<0>(tp), e = get<1>(tp), t = get<2>(tp);

                if (dist[e] > dist[s] + t)
                    dist[e] = dist[s] + t;
            }
        }

        bool flag = true;
        for (auto& tp : edge) {
            int s = get<0>(tp), e = get<1>(tp), t = get<2>(tp);

            if (dist[e] > dist[s] + t) {
                cout << "YES \n";
                flag = false;
                break;
            }
        }

        if (flag) cout << "NO \n";
    }
}