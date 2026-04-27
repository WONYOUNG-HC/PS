#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Prim(int n, int start, vector<int>& w, vector<vector<int>>& p);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> w(n);
    int start, c = 100001;
    for (int i=0; i<n; i++) {
        cin >> w[i];
        if (w[i] < c) {
            start = i;
            c = w[i];
        }
    }

    vector<vector<int>> p(n, vector<int>(n));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> p[i][j];

    cout << Prim(n, start, w, p);

    return 0;
}

int Prim(int n, int start, vector<int>& w, vector<vector<int>>& p) {
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i=0; i<n; i++) {
        if (i == start) continue;
        pq.emplace(p[start][i], i);
        pq.emplace(w[i], i);
    }
    visited[start] = true;
    int cnt = 1, ans = w[start];

    while (cnt != n) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        cnt++;
        ans += cost;

        for (int i=0; i<n; i++) {
            if (!visited[i])
                pq.emplace(p[node][i], i);
        }
    }

    return ans;
}