#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum Status {NOT_VISITED, VISITED, NOT_ADAPTER, ADAPTER};

int n;
vector<int> graph[1000010];
Status status[1000010];


bool dfs(int cur) {
    bool child_adapter = true;
    bool is_leaf = true;
    
    status[cur] = VISITED;

    for (int next : graph[cur]) {
        if (status[next] == NOT_VISITED) {
            if (!dfs(next)) {
                child_adapter = false;
            }

            is_leaf = false;
        }
    }

    if (is_leaf || child_adapter) {
        status[cur] = NOT_ADAPTER;

        return false;
    }

    status[cur] = ADAPTER;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;

        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    cout << count(status + 1, status + n + 1, ADAPTER);
}