#include <iostream>

using namespace std;
using ll = long long;

int n, q;
ll arr[100010], tree[400010];

ll init(int start, int end, int node) {
    if (start == end)
        return tree[node] = arr[start];
    
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll query(int start, int end, int node, int left, int right) {
    if (end < left || start > right)  
        return 0;
    
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

ll update(int start, int end, int node, int index, int value) {
    if (end < index || start > index)
        return tree[node];

    if (start == end)
        return tree[node] = value;

    int mid = (start + end) / 2;
    return tree[node] = update(start, mid, node * 2, index, value) + update(mid + 1, end, node * 2 + 1, index, value);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    init(1, n, 1);
    for (int i = 0; i < q; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        if (x > y) swap(x, y);
        cout << query(1, n, 1, x, y) << '\n';
        update(1, n, 1, a, b);
    }
}