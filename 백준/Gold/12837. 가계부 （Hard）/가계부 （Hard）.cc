#include <iostream>

using namespace std;
using ll = long long;

int n, q;
ll tree[4000010];

ll update(int left, int right, int node, int index, ll value) {
    if (index < left || right < index) {
        return tree[node];
    }

    if (left == right) {
        return tree[node] += value;
    }

    int mid = (left + right) / 2;

    ll left_value = update(left, mid, node * 2, index, value);
    ll right_value = update(mid + 1, right, node * 2 + 1, index, value);

    return tree[node] = left_value + right_value;
}

ll query(int left, int right, int node, int start, int end) {
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
    
    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        if (a == 1) {
            update(1, n, 1, b, c);
        } else {
            cout << query(1, n, 1, b, c) << '\n';
        }
    }
}