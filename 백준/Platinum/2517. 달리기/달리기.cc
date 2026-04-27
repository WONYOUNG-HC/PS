#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[500010];
int tree[2000010];

int query(int start, int end, int node, int left, int right) {
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

int update(int start, int end, int node, int idx) {
    if (idx < start || end < idx) {
        return tree[node];
    }

    if (start == end) {
        return tree[node] = 1;
    }

    int mid = (start + end) / 2;

    int left_value = update(start, mid, node * 2, idx);
    int right_value = update(mid + 1, end, node * 2 + 1, idx);

    return tree[node] = left_value + right_value;
}

void compress() {
    int sorted[500010];

    copy_n(arr + 1, n, sorted + 1);

    sort(sorted + 1, sorted + n + 1);

    for (int i = 1; i <= n; i++) {
        arr[i] = upper_bound(sorted + 1, sorted + n + 1, arr[i]) - (sorted + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    compress();

    for (int i = 1; i <= n; i++) {
        cout << i - query(1, n, 1, 1, arr[i]) << '\n';

        update(1, n, 1, arr[i]);
    }
}