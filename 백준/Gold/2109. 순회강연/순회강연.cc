#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

struct cmp {
    bool operator()(pii a, pii b) const {
        if (a.first == b.first) {
            return a.second < b.second;
        }

        return a.first > b.first;
    }
};

int n;
pii arr[10010];
priority_queue<pii, vector<pii>, cmp> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr + n, [](pii a, pii b) -> bool {
        if (a.second == b.second) {
            return a.first > b.first;
        }

        return a.second < b.second;
    });

    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);

        if (pq.size() > arr[i].second) {
            pq.pop();
        }
    }

    int ans = 0;
    
    while (!pq.empty()) {
        ans += pq.top().first;
        pq.pop();
    }

    cout << ans; 
}