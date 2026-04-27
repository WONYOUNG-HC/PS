#include <iostream>

using namespace std;
using pii = pair<int, int>;

int n, k;
int arr[100010];
pii tree[400010];

pii get_value(pii left_value, pii right_value) {
    return {min(left_value.first, right_value.first), max(left_value.second, right_value.second)};
}

pii get_value(int num) {
    return {num, num};
}

pii init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = get_value(start);
    }

    int mid = (start + end) / 2;

    pii left_value = init(start, mid, node * 2);
    pii right_value = init(mid + 1, end, node * 2 + 1);

    return tree[node] = get_value(left_value, right_value);
}

pii update(int start, int end, int node, int idx, int num) {
    if (idx < start || end < idx) {
        return tree[node];
    }

    if (start == end) {
        return tree[node] = get_value(num);
    }

    int mid = (start + end) / 2;

    pii left_value = update(start, mid, node * 2, idx, num);
    pii right_value = update(mid + 1, end, node * 2 + 1, idx, num);

    return tree[node] = get_value(left_value, right_value);
}

pii query(int start, int end, int node, int left, int right) {
    if (right < start || end < left) {
        return {1e9, -1};
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    pii left_value = query(start, mid, node * 2, left, right);
    pii right_value = query(mid + 1, end, node * 2 + 1, left, right);

    return get_value(left_value, right_value);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    while (tc--) {
        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            arr[i] = i;
        }

        init(1, n, 1);

        for (int i = 0; i < k; i++) {
            int q, a, b;

            cin >> q >> a >> b;

            a += 1;
            b += 1;

            if (q == 0) {
                update(1, n, 1, a, arr[b]);
                update(1, n, 1, b, arr[a]);
                swap(arr[a], arr[b]);
            } else {
                pii value = query(1, n, 1, a, b);

                if (value.first == a && value.second == b) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }
}