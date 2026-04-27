#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[100010];
vector<int> tree[400010];

vector<int> init(int start, int end, int node) {
    if (start == end) {
        tree[node].push_back(arr[start]);

        return tree[node];
    }

    int mid = (start + end) / 2;

    vector<int> left_vec = init(start, mid, node * 2);
    vector<int> right_vec = init(mid + 1, end, node * 2 + 1);

    tree[node].resize(end - start + 1);

    merge(left_vec.begin(), left_vec.end(), right_vec.begin(), right_vec.end(), tree[node].begin());

    return tree[node];
}

int query(int start, int end, int node, int left, int right, int value) {
    if (end < left || right < start) {
        return 0;
    }

    if (left <= start && end <= right) {
        return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), value);
    }

    int mid = (start + end) / 2;

    int left_value = query(start, mid, node * 2, left, right, value);
    int right_value = query(mid + 1, end, node * 2 + 1, left, right, value);

    return left_value + right_value;
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

    for (int i = 1; i <= m; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        cout << query(1, n, 1, a, b, c) << '\n';
    }
}