#include <iostream>
#include <queue>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

bool Pred(const pii& left, const pii& right) {
    if (left.first != right.first)
        return left.first < right.first;
    return left.second > right.second;
}

int n;
pii arr[200010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr, arr + n, Pred);
    priority_queue<int, vector<int>, greater<>> pq;

    int cur = 1;
    for (int i = 0; i < n; i++) {
        if (cur <= arr[i].first) {
            pq.push(arr[i].second);
            cur++;
        }
        else {
            if (pq.top() < arr[i].second) {
                pq.pop();
                pq.push(arr[i].second);
            }
        }
    }

    int ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;
}