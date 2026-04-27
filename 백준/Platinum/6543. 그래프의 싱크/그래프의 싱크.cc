#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

#define N 5010

using namespace std;

int n, m, scc_cnt;
vector<int> adj[N], adj_inv[N];
bool vis[N];
stack<int> st;
set<int> scc[N];

void DFS(int node) {
    vis[node] = true;

    for (int next : adj[node])
        if (!vis[next])
            DFS(next);

    st.push(node);
}

void DFSInv(int node) {
    vis[node] = true;

    for (int prev : adj_inv[node])
        if (!vis[prev])
            DFSInv(prev);

    scc[scc_cnt].insert(node);
}

void solve() {
    cin >> m;

    fill(adj, adj + N, vector<int>());
    fill(adj_inv, adj_inv + N, vector<int>());
    fill(vis, vis + N, false);
    fill(scc, scc + N, set<int>());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj_inv[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            DFS(i);

    scc_cnt = 0;
    fill(vis, vis + N, false);
    while (!st.empty()) {
        if (!vis[st.top()])
            DFSInv(st.top()), scc_cnt++;
        st.pop();
    }

    set<int> ans;
    for (int i = 0; i < scc_cnt; i++) {
        bool flag = true;
        for (int node : scc[i]) {
            for (int next : adj[node]) {
                if (scc[i].find(next) == scc[i].end()) {
                    flag = false;
                }
            }
        }

        if (flag) {
            for (int x : scc[i]) {
                ans.insert(x);
            }
        }
    }

    for (int a : ans)
        cout << a << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while (n != 0) {
        solve();
        cin >> n;
    }
}