#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, m;
vector<pii> graph[100010];
pair<int, pii> edges[100010];
int sz[100010];
int depth[100010];
int parent[100010];
int in[100010];
int out[100010];
int top[100010];
int tree[400010];

void dfs1(int cur, int par) {
    sz[cur] = 1;
    depth[cur] = depth[par] + 1;
    parent[cur] = par;

    for (int i = 0; i < graph[cur].size(); i++) {
        if (graph[cur][i].first == par) {
            graph[cur].erase(graph[cur].begin() + i);
            break;
        }
    }

    for (auto child : graph[cur]) {
        dfs1(child.first, cur);
        sz[cur] += sz[child.first];
    }

    sort(graph[cur].begin(), graph[cur].end(), [](pii left, pii right) -> bool {
        if (sz[left.first] == sz[right.first]) {
            return left.first < right.first;
        }
        return sz[left.first] > sz[right.first];
    });
}

void dfs2(int cur, int &cnt) {
    cnt += 1;
    in[cur] = cnt;

    for (auto child : graph[cur]) {
        top[child.first] = (child.first == graph[cur][0].first ? top[cur] : child.first);
        dfs2(child.first, cnt);
    }

    out[cur] = cnt;
}

void update(int start, int end, int node, int target, int val) {
    if (target < start || target > end) {
        return;
    }
    
    if (start == end) {
        tree[node] = val;

        return;
    }
    
    int mid = (start + end) / 2;

    update(start, mid, node * 2, target, val);
    update(mid + 1, end, node * 2 + 1, target, val);
    
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int query(int start, int end, int node, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }
    
    int mid = (start + end) / 2;

    return max(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}

int query_path(int u, int v) {
    int ret = 0;

    while (top[u] != top[v]) {
        if (depth[top[u]] < depth[top[v]]) {
            swap(u, v);
        }

        ret = max(ret, query(1, n, 1, in[top[u]], in[u]));

        u = parent[top[u]];
    }
    
    if (depth[u] > depth[v]) {
        swap(u, v);
    }
    
    if (u != v) {
        ret = max(ret, query(1, n, 1, in[u] + 1, in[v]));
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, {u, v}};
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }

    int cnt = 0;

    dfs1(1, 0);
    
    top[1] = 1; 
    dfs2(1, cnt);

    for (auto edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        int w = edge.first;

        int target_node = (depth[u] > depth[v]) ? u : v;
        
        update(1, n, 1, in[target_node], w);
    }

    cin >> m;

    while (m--) {
        int type;

        cin >> type;
        
        if (type == 1) {
            int i, c;

            cin >> i >> c;
            
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int target_node = (depth[u] > depth[v]) ? u : v;
            
            update(1, n, 1, in[target_node], c);
        } 
        else if (type == 2) {
            int u, v;

            cin >> u >> v;
            cout << query_path(u, v) << "\n";
        }
    }
}