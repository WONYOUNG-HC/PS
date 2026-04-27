#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> state;
vector<int> stack;

bool dfs(int node) {
    for (int next : graph[node]) {
        if (state[next] == -1) {
            state[next] = 0;
            dfs(next);
        }
        else if (state[next] == 0) {
            return false;
        }
    }

    state[node] = 1;
    stack.push_back(node);

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    state.resize(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a;

        if (a > 0) cin >> b;
        for (int j = 1; j < a; j++) {
            cin >> c;
            graph[b].push_back(c);
            b = c;
        }
    }

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (state[i] == -1) {
            state[i] = 0;
            flag = dfs(i);
        }
    }

    if (!flag) {
        cout << 0;
        return 0;
    }

    for (auto ri = stack.rbegin(); ri != stack.rend(); ri++)
        cout << *ri << '\n';
}