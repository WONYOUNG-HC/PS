#include <iostream>

#define ll long long

using namespace std;

const int N = 1'000'010;
int n, m, k;
ll arr[N], tree[4 * N];

ll init(int start, int end, int node) {
     if (start == end)
         return tree[node] = arr[start];

     int mid = (start + end) / 2;

     return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int node, int left, int right) {
    if (left > end || right < start)
        return 0;

    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;

    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, ll dif) {
    if (index < start || index > end)
        return;

    tree[node] += dif;

    if (start == end)
        return;

    int mid = (start + end) / 2;

    update(start, mid, node * 2, index, dif);
    update(mid + 1, end, node * 2 + 1, index, dif);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    init(1, n, 1);

    for (int i = 0; i < m + k; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            update(1, n, 1, b, c - arr[b]);
            arr[b] = c;
        }
        else {
            cout << sum(1, n, 1, b, c) << '\n';
        }
    }
}