#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> dist(max(n, k) * 2 + 10, 1e9);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, n);
    dist[n] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cur == k)
            break;

        if (cur < max(n, k) && dist[cur + 1] > cost + 1) {
            dist[cur + 1] = cost + 1;
            pq.emplace(dist[cur + 1], cur + 1);
        }

        if (cur > 0 && dist[cur - 1] > cost + 1) {
            dist[cur - 1] = cost + 1;
            pq.emplace(dist[cur - 1], cur - 1);
        }

        if (cur < max(n, k) && dist[cur * 2] > cost) {
            dist[cur * 2] = cost;
            pq.emplace(dist[cur * 2], cur * 2);
        }
    }

    cout << dist[k];
}