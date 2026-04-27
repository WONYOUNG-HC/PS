#include <iostream>

using namespace std;
using ll = long long;

int n, m;
ll tree[4000010];

ll sum(int start, int end, int node, int left, int right) {
    if (start > right || end < left) 
        return 0;
    
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

ll modify(int start, int end, int node, int index, int value) {
    if (index < start || index > end)
        return tree[node];
    
    if (start == end) 
        return tree[node] = value;
    
    int mid = (start + end) / 2;
    return tree[node] = modify(start, mid, node * 2, index, value) + modify(mid + 1, end, node * 2 + 1, index, value);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0) 
            cout << sum(1, n, 1, min(b, c), max(b, c)) << '\n';
        else
            modify(1, n, 1, b, c);
    }
}