#include <iostream>

using namespace std;

int n;
int arr[500010];
int upper[500010];
int lower_idx[1000010];
int tree[2000100];

int query(int start, int end, int node, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, int diff) {
    if (index < start || index > end) {
        return;
    }

    tree[node] += diff;

    if (start == end) {
        return;
    }

    int mid = (start + end) / 2;

    update(start, mid, node * 2, index, diff);
    update(mid + 1, end, node * 2 + 1, index, diff);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> upper[i];
    }

    for (int i = 1; i <= n; i++) {
        int l;

        cin >> l;
        lower_idx[l] = i;
    }

    for (int i = 1; i <= n; i++) {
        arr[i] = lower_idx[upper[i]];
    }

    //
    //
    //

    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += query(1, n, 1, arr[i], n);

        update(1, n, 1, arr[i], 1);
    }

    cout << ans;
}