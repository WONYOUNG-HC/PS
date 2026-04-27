#include <iostream>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, w;
pii arr[1010];
int dp[1010][1010];
int path[1010][1010];

int calc(pii from, pii to) {
    return abs(from.first - to.first) + abs(from.second - to.second);
}

int f(int u, int v) {
    if (u == w || v == w) {
        return 0;
    }

    if (dp[u][v] != -1) {
        return dp[u][v];
    }

    int next = max(u, v) + 1;
    pii cur_u = (u == 0 ? make_pair(1, 1) : arr[u]);
    pii cur_v = (v == 0 ? make_pair(n, n) : arr[v]);

    int next_u = f(next, v) + calc(cur_u, arr[next]);
    int next_v = f(u, next) + calc(cur_v, arr[next]);

    path[u][v] = (next_u < next_v ? 1 : 2);

    return dp[u][v] = min(next_u, next_v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;

    for (int i = 1; i <= w; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    fill(dp[0], dp[0] + 1010 * 1010, -1);

    cout << f(0, 0) << '\n';

    int u = 0;
    int v = 0;

    while (u < w && v < w) {
        int pos = path[u][v];

        cout << pos << '\n';

        (pos == 1 ? u : v) = max(u, v) + 1;
    }
}