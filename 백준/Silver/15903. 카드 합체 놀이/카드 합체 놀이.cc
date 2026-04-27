#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        long long a; cin >> a;
        pq.push(a);
    }

    for (int i = 0; i < m; i++) {
        long long m1 = pq.top(); pq.pop();
        long long m2 = pq.top(); pq.pop();

        pq.push(m1 + m2);
        pq.push(m1 + m2);
    }

    long long ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;
}