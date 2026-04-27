#include <iostream>

using namespace std;

int n, m;
int arr[100010];
int tree[400010];

int init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;

    int left_value = init(start, mid, node * 2);
    int right_value = init(mid + 1, end, node * 2 + 1);

    return tree[node] = min(left_value, right_value);
}

int query(int start, int end, int node, int left, int right) {
    if (right < start || end < left) {
        return 2e9;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    int left_value = query(start, mid, node * 2, left, right);
    int right_value = query(mid + 1, end, node * 2 + 1, left, right);

    return min(left_value, right_value);
}

int update(int start, int end, int node, int index, int value) {
    if (index < start || end < index) {
        return tree[node];
    }

    if (start == end) {
        return tree[node] = value;
    }

    int mid = (start + end) / 2;

    int left_value = update(start, mid, node * 2, index, value);
    int right_value = update(mid + 1, end, node * 2 + 1, index, value);

    return tree[node] = min(left_value, right_value);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    init(1, n, 1);

    cin >> m;

    for (int i = 0; i < m; i++) {
        int c, a, b;

        cin >> c >> a >> b;

        if (c == 1) {
            update(1, n, 1, a, b);
        } else {
            cout << query(1, n, 1, a, b) << '\n';
        }
    }
}