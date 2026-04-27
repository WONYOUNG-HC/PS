#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> build;
vector<int> in_degree;

void Init(int n) {
    graph.clear();
    build.clear();
    in_degree.clear();

    graph.resize(n + 1);
    build.resize(n + 1);
    in_degree.resize(n + 1);
}

int solve() {
    int n, k;
    cin >> n >> k;

    Init(n);
    for (int i = 1; i <= n; i++) {
        cin >> build[i];
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        in_degree[y]++;
    }

    int w; cin >> w;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) pq.emplace(build[i], i);
    }

    while (!pq.empty()) {
        int cur_time = pq.top().first;
        int cur_building = pq.top().second;
        pq.pop();

        if (cur_building == w)
            return cur_time;

        for (int next : graph[cur_building]) {
            in_degree[next]--;

            if (in_degree[next] == 0) {
                build[next] += cur_time;
                pq.emplace(build[next], next);
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        cout << solve() << '\n';
    }
}