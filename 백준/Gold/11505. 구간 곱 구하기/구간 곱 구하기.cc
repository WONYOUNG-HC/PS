#include <iostream>

using namespace std;
using ll = long long;

int n, m, k;
ll arr[1000010];
ll tree[4000010];
const ll mod = 1e9 + 7;

ll init(int start, int end, int node) {
    if (start == end)
        return tree[node] = arr[start];

    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1) % mod;
}

ll mul(int start, int end, int node, int left, int right) {
    if (left > end || right < start)
        return 1;
    
    if (left <= start && end <= right)
        return tree[node];
    
    int mid = (start + end) / 2;
    return mul(start, mid, node * 2, left, right) * mul(mid + 1, end, node * 2 + 1, left, right) % mod;
}

ll update(int start, int end, int node, int index, ll value) {
    if (index < start || end < index)
        return tree[node];
    
    if (start == end)
        return tree[node] = value;

    int mid = (start + end) / 2;
    return tree[node] = update(start, mid, node * 2, index, value) * update(mid + 1, end, node * 2 + 1, index, value) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    init(0, n - 1, 1);
    for (int i = 0; i < m + k; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            update(0, n - 1, 1, b - 1, c);
            arr[b - 1] = c;
        }
        else   
            cout << mul(0, n - 1, 1, b - 1, c - 1) << '\n';
    }
}