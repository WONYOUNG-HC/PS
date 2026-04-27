#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> inverse_graph;
vector<bool> visited;
vector<int> scc;
int last;

void DFS(int node) {
    visited[node] = true;

    for (int next : graph[node]) {
        if (!visited[next]) DFS(next);
    }

    last = node;
}

void DFSInverse(int node) {
    visited[node] = true;

    for (int next : inverse_graph[node]) {
        if (!visited[next]) DFSInverse(next);
    }

    scc.push_back(node);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;

        graph.resize(n);
        inverse_graph.resize(n);

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            graph[a].push_back(b);
            inverse_graph[b].push_back(a);
        }

        visited.resize(n);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) DFS(i);
        }

        visited.clear();
        visited.resize(n);
        DFSInverse(last);

        visited.clear();
        visited.resize(n);
        DFS(scc[0]);

        bool ans = true;

        for (int i = 0; i < n; i++)
            if (!visited[i]) ans = false;

        if (ans) {
            sort(scc.begin(), scc.end());
            for (int node : scc)
                cout << node << '\n';
        }
        else
            cout << "Confused \n";

        cout << '\n';

        graph.clear();
        inverse_graph.clear();
        visited.clear();
        scc.clear();
    }
}