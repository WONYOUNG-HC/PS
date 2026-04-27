#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = unsigned long long;

const ll MOD = 1LL << 32;

int n, m;
vector<int> graph[500010];
int sz[500010];
int depth[500010];
int parent[500010];
int in[500010];
int out[500010];
int top[500010];
ll tree[2000010];
ll lazy_add[2000010];
ll lazy_mul[2000010];

void dfs1(int cur, int par) {
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

void update_lazy(int start, int end, int node) {
    if (lazy_add[node] == 0 && lazy_mul[node] == 1) {
        return;
    }

    tree[node] *= lazy_mul[node];
    tree[node] %= MOD;

    tree[node] += lazy_add[node] * (end - start + 1);
    tree[node] %= MOD;

    if (start != end) {
        lazy_mul[node * 2] *= lazy_mul[node];
        lazy_mul[node * 2] %= MOD;

        lazy_add[node * 2] *= lazy_mul[node];
        lazy_add[node * 2] %= MOD;

        lazy_add[node * 2] += lazy_add[node];
        lazy_add[node * 2] %= MOD;

        lazy_mul[node * 2 + 1] *= lazy_mul[node];
        lazy_mul[node * 2 + 1] %= MOD;

        lazy_add[node * 2 + 1] *= lazy_mul[node];
        lazy_add[node * 2 + 1] %= MOD;

        lazy_add[node * 2 + 1] += lazy_add[node];
        lazy_add[node * 2 + 1] %= MOD;
    }

    lazy_mul[node] = 1;
    lazy_add[node] = 0;
}

ll update(int start, int end, int node, int left, int right, ll add, ll mul) {
    update_lazy(start, end, node);

    if (right < start || end < left) {
        return tree[node];
    }

    if (left <= start && end <= right) {
        lazy_mul[node] = mul;
        lazy_add[node] = add;

        update_lazy(start, end, node); 
        
        return tree[node];
    }

    int mid = (start + end) / 2;

    ll left_value = update(start, mid, node * 2, left, right, add, mul);
    ll right_value = update(mid + 1, end, node * 2 + 1, left, right, add, mul);

    tree[node] = left_value + right_value;
    tree[node] %= MOD;

    return tree[node];
}

ll query(int start, int end, int node, int left, int right) {
    update_lazy(start, end, node);

    if (right < start || end < left) {
        return 0;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    ll left_value = query(start, mid, node * 2, left, right);
    ll right_value = query(mid + 1, end, node * 2 + 1, left, right);

    return (left_value + right_value) % MOD;
}

void update_path(int u, int v, ll add, ll mul) {
    while (top[u] != top[v]) {
        if (depth[top[u]] < depth[top[v]]) {
            swap(u, v);
        }

        update(1, n, 1, in[top[u]], in[u], add, mul);

        u = parent[top[u]];
    }

    if (depth[u] > depth[v]) {
        swap(u, v);
    }

    update(1, n, 1, in[u], in[v], add, mul);
}

ll query_path(int u, int v) {
    ll ret = 0;

    while (top[u] != top[v]) {
        if (depth[top[u]] < depth[top[v]]) {
            swap(u, v);
        }

        ret += query(1, n, 1, in[top[u]], in[u]);
        ret %= MOD;

        u = parent[top[u]];
    }

    if (depth[u] > depth[v]) {
        swap(u, v);
    }

    ret += query(1, n, 1, in[u], in[v]);
    ret %= MOD;

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n - 1; i++) {
        int s, e;

        cin >> s >> e;

        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    //
    //
    //

    int cnt = 0;
    top[1] = 1;

    dfs1(1, 0);
    dfs2(1, cnt);

    //
    //
    //

    fill(lazy_mul, lazy_mul + 2000010, 1);

    for (int i = 0; i < m; i++) {
        int op, x, y, v;

        cin >> op;

        switch (op) {
            case 1: {
                cin >> x >> v;

                update(1, n, 1, in[x], out[x], v, 1);

                break;
            }
            case 2: {
                cin >> x >> y >> v;

                update_path(x, y, v, 1);

                break;
            }
            case 3: {
                cin >> x >> v;

                update(1, n, 1, in[x], out[x], 0, v);

                break;
            }
            case 4: {
                cin >> x >> y >> v;
                
                update_path(x, y, 0, v);

                break;
            }
            case 5: {
                cin >> x;

                cout << query(1, n, 1, in[x], out[x]) << '\n';

                break;
            }
            case 6: {
                cin >> x >> y;

                cout << query_path(x, y) << '\n';

                break;
            }
        }
    }
}