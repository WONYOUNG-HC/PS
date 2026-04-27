#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, m;
vector<int> graph[20010];
vector<int> graph_inv[20010];
bool vis[20010];
stack<int> st;
int scc_n[20010];
vector<vector<int>> scc;
bool ans[10010];

int no(int x) {
    if (x <= n) {
        return x + n;
    }

    return x - n;
}

void dfs(int cur) {
    vis[cur] = true;

    for (int next : graph[cur]) {
        if (!vis[next]) {
            dfs(next);
        }
    }

    st.push(cur);
}

void dfs_inv(int cur, vector<int> &v, int &num) {
    vis[cur] = true;
    scc_n[cur] = num;
    v.push_back(cur);

    for (int next : graph_inv[cur]) {
        if (!vis[next]) {
            dfs_inv(next, v, num);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;

        cin >> u >> v;

        if (u < 0) {
            u = -u + n;
        }

        if (v < 0) {
            v = -v + n;
        }

        graph[no(u)].push_back(v);
        graph[no(v)].push_back(u);

        graph_inv[u].push_back(no(v));
        graph_inv[v].push_back(no(u));
    }

    //
    //
    //

    for (int i = 1; i <= 2 * n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    //
    //
    //

    fill_n(vis, 20010, false);
    int num = 0;

    while (!st.empty()) {
        if (!vis[st.top()]) {
            vector<int> v;

            dfs_inv(st.top(), v, num);

            scc.push_back(v);
            num += 1;
        }

        st.pop();
    }

    //
    //
    //

    bool possbile = true;

    for (int i = 1; i <= n; i++) {
        if (scc_n[i] == scc_n[i + n]) {
            possbile = false;
            break;
        }
    }

    cout << possbile << '\n';

    if (!possbile) {
        return 0;
    }

    //
    //
    //

    fill_n(vis, 20101, false);
    vector<pair<int, int>> order;

    for (int i = 0; i < scc.size(); i++) {
        order.emplace_back(i, scc[i][0]);
    }

    sort(order.rbegin(), order.rend());

    for (auto pr : order) {
        int idx, rep;
        tie(idx, rep) = pr;

        for (int x : scc[idx]) {
            if (vis[x] || vis[no(x)]) {
                continue;
            }

            vis[x] = true;
            ans[(x <= n) ? x : x - n] = (x <= n);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}