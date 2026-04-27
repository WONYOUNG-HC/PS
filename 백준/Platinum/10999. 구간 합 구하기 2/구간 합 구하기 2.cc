#include <iostream>

using namespace std;
using ll = long long;

int n, m, k;
ll arr[1000010];
ll tree[4000010];
ll lazy[4000010];

ll init(int left, int right, int node) {
    if (left == right) {
        return tree[node] = arr[left];
    }

    int mid = (left + right) / 2;

    ll left_value = init(left, mid, node * 2);
    ll right_value = init(mid + 1, right, node * 2 + 1);

    return tree[node] = left_value + right_value;
}

void update_lazy(int left, int right, int node) {
    if (lazy[node] != 0) {
        tree[node] += (right - left + 1) * lazy[node];

        if (left != right) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }
}

ll update_range(int left, int right, int node, int start, int end, ll diff) {
    update_lazy(left, right, node);

    if (end < left || right < start) {
        return tree[node];
    }

    if (start <= left && right <= end) {
        tree[node] += (right - left + 1) * diff;

        if (left != right) {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }

        return tree[node];
    }

    int mid = (left + right) / 2;

    ll left_value = update_range(left, mid, node * 2, start, end, diff);
    ll right_value = update_range(mid + 1, right, node * 2 + 1, start, end, diff);

    return tree[node] = left_value + right_value;
}

ll query(int left, int right, int node, int start, int end) {
    update_lazy(left, right, node);
    
    if (end < left || right < start) {
        return 0;
    }

    if (start <= left && right <= end) {
        return tree[node];
    }

    int mid = (left + right) / 2;

    ll left_value = query(left, mid, node * 2, start, end);
    ll right_value = query(mid + 1, right, node * 2 + 1, start, end);

    return left_value + right_value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    init(1, n, 1);

    for (int i = 0; i < m + k; i++) {
        ll a, b, c, d;

        cin >> a;

        if (a == 1) {
            cin >> b >> c >> d;

            update_range(1, n, 1, b, c, d);
        } else {
            cin >> b >> c;

            cout << query(1, n, 1, b, c) << '\n';
        }
    }
}