#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100010];
int tree[400010];

bool compare(int a, int b) {
    if (arr[a] == arr[b]) {
        return a < b;
    }

    return arr[a] < arr[b];
}

int init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = start;
    }

    int mid = (start + end) / 2;

    int left = init(start, mid, node * 2);
    int right = init(mid + 1, end, node * 2 + 1);

    if (compare(left, right)) {
        tree[node] = left;
    } else {
        tree[node] = right;
    }

    return tree[node];
}

int query(int start, int end, int node, int left, int right) {
    if (left > end || right < start) {
        return n;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    int left_index = query(start, mid, node * 2, left, right);
    int right_index = query(mid + 1, end, node * 2 + 1, left, right);

    if (compare(left_index, right_index)) {
        return left_index;
    }

    return right_index;
}

int update(int start, int end, int node, int index) {
    if (index < start || index > end) {
        return tree[node];
    }

    if (start == end) {
        return tree[node] = index;
    }

    int mid = (start + end) / 2;

    int left = update(start, mid, node * 2, index);
    int right = update(mid + 1, end, node * 2 + 1, index);

    if (compare(left, right)) {
        tree[node] = left;
    } else {
        tree[node] = right;
    }

    return tree[node];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //
    //
    //

    fill_n(tree, 400010, n);
    arr[n] = 1e9 + 7;

    init(0, n - 1, 1);
    //
    //
    //

    cin >> m;

    while (m--) {
        int c, a, b;

        cin >> c >> a >> b;
        
        if (c == 1) {
            arr[a - 1] = b;

            update(0, n - 1, 1, a - 1);
        } else {
            cout << query(0, n - 1, 1, a - 1, b - 1) + 1 << '\n';
        }
    }
}