#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> line(n);
    for (int i=0; i<n; i++) {
        int s, e;
        cin >> s >> e;
        line[i] = {s, e};
    }
    sort(line.begin(), line.end());

    int ans = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(line[0].second, line[0].first);
    for (int i=1; i<n; i++) {
        while (!pq.empty() && pq.top().first <= line[i].first)
            pq.pop();
        pq.emplace(line[i].second, line[i].first);

        ans = max(ans, (int)pq.size());
    }

    cout << ans;
}