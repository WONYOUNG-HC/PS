#include <iostream>

using namespace std;

int n, m;
int tree[400010];
bool lazy[400010];

void update_lazy(int start, int end, int node) {
    if (lazy[node]) {
        tree[node] = (end - start + 1) - tree[node];

        if (start != end) {
            lazy[node * 2] ^= true;
            lazy[node * 2 + 1] ^= true;
        }

        lazy[node] = false;
    }
}

int update(int start, int end, int node, int left, int right) {
    update_lazy(start, end, node);

    if (right < start || end < left) {
        return tree[node];
    }

    if (left <= start && end <= right) {
        tree[node] = (end - start + 1) - tree[node];

        if (start != end) {
            lazy[node * 2] ^= true;
            lazy[node * 2 + 1] ^= true;
        }

        return tree[node];
    }

    int mid = (start + end) / 2;

    int left_value = update(start, mid, node * 2, left, right);
    int right_value = update(mid + 1, end, node * 2 + 1, left, right);

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

    for (int i = 0; i < m; i++) {
        int o, s, t;

        cin >> o >> s >> t;

        if (o == 0) {
            update(1, n, 1, s, t);
        } else {
            cout << query(1, n, 1, s, t) << '\n';
        }
    }
}