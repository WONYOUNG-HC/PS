#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int>> graph;
vector<int> in_degree, build;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    graph.resize(n + 1);
    in_degree.resize(n + 1);
    build.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        int c; cin >> c;
        build[i] = c;

        int in = 0, p;
        cin >> p;
        while (p != -1) {
            in++;
            graph[p].push_back(i);
            cin >> p;
        }

        in_degree[i] = in;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0)
            pq.emplace(build[i], i);
    }

    int cur;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        cur = cost;
        build[node] = cur;

        for (int next : graph[node]) {
            in_degree[next]--;

            if (in_degree[next] == 0)
                pq.emplace(build[next] + cur, next);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << build[i] << '\n';
}