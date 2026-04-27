#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    pair<int, int> gas[n];
    for (int i = 0; i < n; i++)
        cin >> gas[i].first >> gas[i].second;

    int l, p;
    cin >> l >> p;

    sort(gas, gas + n);

    priority_queue<int> pq;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int cur = gas[i].first;

        while (!pq.empty() && p < cur) {
            p += pq.top();
            pq.pop();
            ans++;
        }

        if (p < cur)
            break;

        pq.push(gas[i].second);
    }

    while (!pq.empty() && p < l) {
        p += pq.top();
        pq.pop();
        ans++;
    }

    cout << (p >= l ? ans : -1);
}