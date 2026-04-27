#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int n, m;
vector<pii> arr[50010];
int dist[50010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].emplace_back(c, b);
        arr[b].emplace_back(c, a);
    }

    fill(dist, dist + n + 10, 1e9);
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, 1);
    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();

        if (dist[cur.second] < cur.first)
            continue;

        for (pii next : arr[cur.second]) {
            if (dist[next.second] > next.first + cur.first) {
                dist[next.second] = next.first + cur.first;
                pq.emplace(dist[next.second], next.second);
            }
        }
    }

    cout << dist[n];
}