#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, m;
vector<int> graph[200010];
vector<int> graph_inv[200010];
bool vis[200010];
stack<int> st;
int scc[200010];

int flip(int x) {
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

void dfs_inv(int cur, int scc_num) {
    vis[cur] = true;
    scc[cur] = scc_num;

    for (int next : graph_inv[cur]) {
        if (!vis[next]) {
            dfs_inv(next, scc_num);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        if (a < 0) {
            a = -a + n;
        }

        if (b < 0) {
            b = -b + n;
        }

        graph[flip(a)].push_back(b);
        graph[flip(b)].push_back(a);
        graph_inv[b].push_back(flip(a));
        graph_inv[a].push_back(flip(b));
    }

    //
    //
    //

    for (int i = 1; i <= 2 * n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    int scc_num = 1;

    fill_n(vis, 200010, false);

    while (!st.empty()) {
        int cur = st.top();
        st.pop();

        if (!vis[cur]) {
            dfs_inv(cur, scc_num);

            scc_num += 1;
        }
    }

    //
    //
    //

    for (int i = 1; i <= n; i++) {
        if (scc[i] == scc[i + n]) {
            cout << 0;

            return 0;
        }
    }

    cout << 1;
}