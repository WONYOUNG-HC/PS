#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Command {
    string type;
    int a, b;
};

int n, m;
int arr[30010];
Command commands[300010];
vector<int> graph[30010];
int uf_parent[30010];
int uf_level[30010];
bool vis[30010];
int sz[30010];
int depth[30010];
int parent[30010];
int in[30010];
int out[30010];
int top[30010];
int tree[120010];

int uf_find(int x) {
    if (uf_parent[x] == x) {
        return x;
    }

    return uf_parent[x] = uf_find(uf_parent[x]);
}

void uf_merge(int u, int v) {
    int ru = uf_find(u);
    int rv = uf_find(v);

    if (ru == rv) {
        return;
    }

    if (uf_level[ru] < uf_level[rv]) {
        swap(ru, rv);
    }

    uf_parent[rv] = ru;

    if (uf_level[ru] == uf_level[rv]) {
        uf_level[ru] += 1;
    }
}

void dfs1(int cur, int par) {
    vis[cur] = true;
    sz[cur] = 1;
    depth[cur] = depth[par] + 1;
    parent[cur] = par;

    for (int i = 0; i < graph[cur].size(); i++) {
        if (graph[cur][i] == par) {
            graph[cur].erase(graph[cur].begin() + i);

            break;
        }
    }

    for (int child : graph[cur]) {
        dfs1(child, cur);
        sz[cur] += sz[child];
    }

    sort(graph[cur].begin(), graph[cur].end(), [](int left, int right) -> bool {
        if (sz[left] == sz[right]) {
            return left < right;
        }

        return sz[left] > sz[right];
    });
}

void dfs2(int cur, int &cnt) {
    cnt += 1;
    in[cur] = cnt;

    for (int i = 0; i < graph[cur].size(); i++) {
        int child = graph[cur][i];
        
        top[child] = (i == 0 ? top[cur] : child);
        dfs2(child, cnt);
    }

    out[cur] = cnt;
}

int update(int start, int end, int node, int target, int value) {
    if (target < start || end < target) {
        return tree[node];
    }

    if (start == end) {
        return tree[node] = value;
    }

    int mid = (start + end) / 2;

    int left_value = update(start, mid, node * 2, target, value);
    int right_value = update(mid + 1, end, node * 2 + 1, target, value);

    return tree[node] = left_value + right_value;
}

int query(int start, int end, int node, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    int left_value = query(start, mid, node * 2, left, right);
    int right_value = query(mid + 1, end, node * 2 + 1, left, right);

    return left_value + right_value;
}

int query_path(int u, int v) {
    int ret = 0;

    while (top[u] != top[v]) {
        if (depth[top[u]] < depth[top[v]]) {
            swap(u, v);
        }

        ret += query(1, n, 1, in[top[u]], in[u]);

        u = parent[top[u]];
    }

    if (depth[u] > depth[v]) {
        swap(u, v);
    }

    ret += query(1, n, 1, in[u], in[v]);

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cin >> m;

    for (int i = 1; i <= m; i++) {
        cin >> commands[i].type >> commands[i].a >> commands[i].b;
    }

    //
    //
    //

    for (int i = 1; i <= n; i++) {
        uf_level[i] = 1;
        uf_parent[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        if (commands[i].type != "bridge") {
            continue;
        }

        int u = commands[i].a;
        int v = commands[i].b;

        int ru = uf_find(commands[i].a);
        int rv = uf_find(commands[i].b);

        if (ru == rv) {
            continue;
        }

        graph[u].push_back(v);
        graph[v].push_back(u);

        uf_merge(u, v);
    }

    //
    //
    //

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }

        dfs1(i, 0);

        top[i] = i;
        dfs2(i, cnt);
    }

    //
    //
    //

    for (int i = 1; i <= n; i++) {
        uf_level[i] = 1;
        uf_parent[i] = i;

        update(1, n, 1, in[i], arr[i]);
    }

    for (int i = 1; i <= m; i++) {
        if (commands[i].type == "bridge") {
            int u = uf_find(commands[i].a);
            int v = uf_find(commands[i].b);

            if (u != v) {
                cout << "yes" << '\n';
                
                uf_merge(u, v);
            } else {
                cout << "no" << '\n';
            }
        } else if (commands[i].type == "penguins") {
            update(1, n, 1, in[commands[i].a], commands[i].b);
        } else if (commands[i].type == "excursion") {
            int u = uf_find(commands[i].a);
            int v = uf_find(commands[i].b);

            if (u != v) {
                cout << "impossible" << '\n';
            } else {
                cout << query_path(commands[i].a, commands[i].b) << '\n';
            }
        }
    }
}