#include <iostream>
#include <queue>
#include <cmath>

#define pdd pair<double, double>
#define X first
#define Y second

using namespace std;

int n;
pdd arr[110];
double graph[110][110];
bool vis[110];

double dist(pdd a, pdd b) {
    return sqrt((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].X >> arr[i].Y;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = dist(arr[i], arr[j]);
        }
    }

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
    pq.emplace(0, 0);
    int cnt = 0; double ans = 0;

    while (!pq.empty()) {
        double d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (vis[cur])
            continue;

        vis[cur] = true;
        ans += d, cnt++;

        if (cnt == n)
            break;

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                pq.emplace(graph[cur][i], i);
        }
    }

    cout << ans;
}