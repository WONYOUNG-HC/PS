#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, sc;
int cost[110];
char graph[110][110];
bool vis[110];
vector<int> scc[110];
stack<int> st;

void dfs(int node) {
    vis[node] = true;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == '0' || vis[i])
            continue;

        dfs(i);
    }

    st.push(node);
}

void dfs_in(int node) {
    vis[node] = true;

    for (int i = 0; i < n; i++) {
        if (graph[i][node] == '0' || vis[i])
            continue;

        dfs_in(i);
    }

    scc[sc].push_back(node);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> cost[i];
    for (int i = 0; i < n; i++)
        cin >> graph[i];

    for (int i = 0; i < n; i++)
        if (!vis[i]) dfs(i);

    fill_n(vis, 110, false);

    while (!st.empty()) {
        if (!vis[st.top()])
            dfs_in(st.top()), sc++;

        st.pop();
    }

    int ans = 0;
    for (int i = 0; i < sc; i++) {
        int c = 1e9;

        for (int j : scc[i])
            c = min(c, cost[j]);

        ans += c;
    }

    cout << ans;
}