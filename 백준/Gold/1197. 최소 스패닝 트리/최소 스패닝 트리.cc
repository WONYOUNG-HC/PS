#include <iostream>
#include <vector>
#include <queue>

#define INF 0x3fffffff

using namespace std;

vector<pair<int, int>> graph[10001];
bool visited[10001];

int Prim(int v, int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;

    int a, b, c, start = INF;
    for (int i=0; i<e; i++) {
        cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
        graph[b].emplace_back(c, a);

        if (c < start) start = a;
    }

    cout << Prim(v, start);
}

int Prim(int v, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    visited[start] = true;
    for (pair<int, int>& g : graph[start])
        pq.emplace(g.first, g.second);

    int ans = 0, cnt = 1;
    while (cnt != v) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;

        ans += cost;
        visited[node] = true;
        cnt++;

        for (pair<int, int>& g : graph[node])
            if (!visited[g.second]) pq.emplace(g.first, g.second);
    }

    return ans;
}