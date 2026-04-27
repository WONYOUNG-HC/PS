#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n;
pii arr[100010];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = {b, c};
    }

    sort(arr, arr + n);
    pq.push(arr[0].second);
    int ans = 1;
    for (int i = 1; i < n; i++) {
        while (!pq.empty() && pq.top() <= arr[i].first)
            pq.pop();
        pq.push(arr[i].second);

        ans = max(ans, (int)pq.size());
    }

    cout << ans;
}