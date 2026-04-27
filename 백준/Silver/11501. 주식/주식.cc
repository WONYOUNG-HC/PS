#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;

        long long arr[n];
        priority_queue<pair<long long, int>> pq;

        for (int i = 0; i < n; i++) {
            int p; cin >> p;
            arr[i] = p;
            pq.emplace(p, i);
        }

        long long cur = 0, ans = 0, balance = 0;
        for (int i = 0; i < n; i++) {
            while (pq.top().second < i)
                pq.pop();

            if (pq.top().first > arr[i]) {
                balance++;
                cur -= arr[i];
            }
            else {
                ans += balance * arr[i] + cur;
                cur = balance = 0;
            }
        }

        cout << ans << '\n';
    }
}