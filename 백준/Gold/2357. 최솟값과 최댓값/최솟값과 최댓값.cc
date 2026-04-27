#include <iostream>

using namespace std;
using pii = pair<int, int>;

int n, m;
int arr[1000010];
pii tree[1000010];

pii init(int start, int end, int node) {
    if (start == end)
        return tree[node] = {arr[start], arr[start]};
    
    int mid = (start + end) / 2;
    pii value1 = init(start, mid, node * 2);
    pii value2 = init(mid + 1, end, node * 2 + 1);
    return tree[node] = {min(value1.first, value2.first), max(value1.second, value2.second)};
}

pii query(int start, int end, int node, int left, int right) {
    if (end < left || right < start)
        return {1e9 + 10, 0};
    
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    pii value1 = query(start, mid, node * 2, left, right);
    pii value2 = query(mid + 1, end, node * 2 + 1, left, right);
    return {min(value1.first, value2.first), max(value1.second, value2.second)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    init(0, n - 1, 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        pii ans = query(0, n - 1, 1, a - 1, b - 1);
        cout << ans.first << ' ' << ans.second << '\n';
    }
}