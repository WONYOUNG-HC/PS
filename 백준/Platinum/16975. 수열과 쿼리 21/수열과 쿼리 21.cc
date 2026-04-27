#include <iostream>

using namespace std;
using ll = long long;

int n, m;
ll arr[100010];
ll tree[400010];

void update(int start, int end, int node, int left, int right, ll value) {
    if (end < left || right < start) {
        return;
    }

    if (left <= start && end <= right) {
        tree[node] += value;

        return;
    }

    int mid = (start + end) / 2;

    update(start, mid, node * 2, left, right, value);
    update(mid + 1, end, node * 2 + 1, left, right, value);
}

ll query(int start, int end, int node, int idx) {
    if (idx < start || end < idx) {
        return 0;
    }

    if (start == end) {
        return arr[idx] + tree[node];
    }

    int mid = (start + end) / 2;

    ll left_value = query(start, mid, node * 2, idx);
    ll right_value = query(mid + 1, end, node * 2 + 1, idx);

    return left_value + right_value + tree[node];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        ll a, b, c, d;

        cin >> a;

        if (a == 1) {
            cin >> b >> c >> d;

            update(1, n, 1, b, c, d);
        } else {
            cin >> b;

            cout << query(1, n, 1, b) << '\n';
        }
    }
}