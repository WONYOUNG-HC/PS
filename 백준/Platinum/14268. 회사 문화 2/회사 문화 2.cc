#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> graph[100010];
int in[100010];
int out[100010];
int tree[400010];
int lazy[400010];

void dfs(int node, int &cnt) {
    cnt += 1;
    in[node] = cnt;

    for (int next : graph[node]) {
        dfs(next, cnt);
    }

    out[node] = cnt;
}

void update_lazy(int start, int end, int node) {
    if (lazy[node]) {
        tree[node] += lazy[node];

        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }
}

int update(int start, int end, int node, int left, int right, int value) {
    update_lazy(start, end, node);

    if (right < start || end < left) {
        return tree[node];
    }

    if (left <= start && end <= right) {
        tree[node] += value;

        if (start != end) {
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }

        return tree[node];
    }

    int mid = (start + end) / 2;
    int left_value = update(start, mid, node * 2, left, right, value);
    int right_value = update(mid + 1, end, node * 2 + 1, left, right, value);

    return tree[node] = left_value + right_value;
}

int query(int start, int end, int node, int left, int right) {
    update_lazy(start, end, node); 
 
    if (right < start || end < left) {
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int parent;

        cin >> parent;

        if (parent == -1) {
            continue;
        }

        graph[parent].push_back(i);
    }

    int cnt = 0;

    dfs(1, cnt);

    for (int i = 0; i < m; i++) {
        int q, x, w;

        cin >> q >> x;

        if (q == 1) {
            cin >> w;
            
            update(1, n, 1, in[x], out[x], w);
        } else if (q == 2) {
            cout << query(1, n, 1, in[x], in[x]) << '\n';
        }
    }
}