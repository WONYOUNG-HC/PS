#include <iostream>
#include <algorithm>
#include <numeric>

#define pii pair<int, int>
#define R first
#define C second

using namespace std;

int n, m, nh, nc, ans = 1e9;
pii house[110], chicken[15];
bool active[15];
int dist[110];

void recur(int cnt, int idx) {
    if (cnt == m) {
        fill(dist, dist + nh, 1e9);

        for (int i = 0; i < nh; i++) {
            for (int j = 0; j < nc; j++) {
                if (!active[j])
                    continue;

                dist[i] = min(dist[i], abs(house[i].R - chicken[j].R) + abs(house[i].C - chicken[j].C));
            }
        }

        ans = min(ans, accumulate(dist, dist + nh, 0));

        return;
    }

    for (int i = idx; i < nc; i++) {
        active[i] = true;
        recur(cnt + 1, i + 1);
        active[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k; cin >> k;

            if (k == 1)
                house[nh++] = {i, j};
            else if (k == 2)
                chicken[nc++] = {i, j};
        }
    }

    recur(0, 0);

    cout << ans;
}