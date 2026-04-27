#include <iostream>

using namespace std;

int n, m;
int arr[100010];
int tree[400010];

int init(int start, int end, int node) {
    if (start == end)
        return tree[node] = arr[start];
    
    int mid = (start + end) / 2;
    return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int query(int start, int end, int node, int left, int right) {
    if (end < left || start > right)
        return 1e9 + 10;
    
    if (left <= start && end <= right)
        return tree[node];
    
    int mid = (start + end) / 2;
    return min(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
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
        cout << query(0, n - 1, 1, a - 1, b - 1) << '\n';
    }   
}