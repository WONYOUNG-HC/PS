#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    multiset<pair<int, int>> ms;
    for (int i=0; i<n; i++) {
        int start, end;
        cin >> start >> end;
        ms.insert({start, end});
    }

    int ans = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (const pair<int, int>& pr : ms) {
        while (!pq.empty() && pq.top().first <= pr.first)
            pq.pop();

        pq.push({pr.second, pr.first});

        if (ans < (int)pq.size()) ans = (int)pq.size();
    }

    cout << ans;
}