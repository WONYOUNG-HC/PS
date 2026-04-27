#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define N 100
#define INF 1e9
#define START 0
#define END 25

using namespace std;

vector<vector<int>> capacity(N, vector<int>(N));
vector<vector<int>> edge(N);

inline int ctoi(char c) {
    return c - 'A';
}

int MaxFlow();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b; int c;
        cin >> a >> b >> c;

        capacity[ctoi(a)][ctoi(b)] += c;
        capacity[ctoi(b)][ctoi(a)] += c;
        edge[ctoi(a)].push_back(ctoi(b));
        edge[ctoi(b)].push_back(ctoi(a));
    }

    cout << MaxFlow();
}

bool bfs(vector<int>& parent, int& flow) {
    fill(parent.begin(), parent.end(), -1);
    parent[START] = -2;
    queue<pair<int, int>> q;
    q.emplace(START, INF);

    while (!q.empty()) {
        int node = q.front().first;
        int cost = q.front().second;
        q.pop();

        for (int next : edge[node]) {
            if (parent[next] == -1 && capacity[node][next] > 0) {
                parent[next] = node;
                flow = min(cost, capacity[node][next]);

                if (next == END)
                    return true;

                q.emplace(next, flow);
            }
        }
    }

    return false;
}

int MaxFlow() {
    int max_flow = 0;
    vector<int> parent(N);
    int flow;

    while (bfs(parent, flow)) {
        max_flow += flow;
        int node = END;

        while (node != START) {
            int prev = parent[node];
            capacity[prev][node] -= flow;
            capacity[node][prev] += flow;
            node = prev;
        }
    }

    return max_flow;
}