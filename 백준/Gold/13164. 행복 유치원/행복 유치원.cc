#include <iostream>
#include <queue>

using namespace std;

int n, k;
int arr[300010];
priority_queue<long long> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        pq.push(arr[i + 1] - arr[i]);
    }

    for (int i = 0; i < k - 1; i++) {
        pq.pop();
    }

    long long ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;
}