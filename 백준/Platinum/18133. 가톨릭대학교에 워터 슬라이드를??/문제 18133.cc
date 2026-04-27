#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
vector<int> graph[100010];
vector<int> graph_inv[100010];
bool vis[100010];
stack<int> st;
vector<set<int>> scc;

void dfs(int cur) {
    vis[cur] = true;

    for (int next : graph[cur]) {
        if (!vis[next]) {
            dfs(next);
        }
    }

    st.push(cur);
}

void dfs_inv(int cur, set<int> &s) {
    vis[cur] = true;
    s.insert(cur);

    for (int next : graph_inv[cur]) {
        if (!vis[next]) {
            dfs_inv(next, s);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;

        cin >> x >> y;

        graph[x].push_back(y);
        graph_inv[y].push_back(x);
    }

    //
    //
    //

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    fill_n(vis, n + 10, false);

    do {
        int cur = st.top();
        st.pop();

        if (vis[cur]) {
            continue;
        }

        set<int> s;

        dfs_inv(cur, s);

        scc.push_back(s);
    } while (!st.empty());

    //
    //
    //

    int ans = 0;

    for (auto s : scc) {
        bool is_sink = true;

        for (int node : s) {
            for (int next : graph_inv[node]) {
                if (s.find(next) == s.end()) {
                    is_sink = false;
                    break;
                }
            }

            if (!is_sink) {
                break;
            }
        }

        if (is_sink) {
            ans += 1;
        }
    }

    cout << ans;
}