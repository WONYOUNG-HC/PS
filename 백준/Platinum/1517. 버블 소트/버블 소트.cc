#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int, int> arr[500010];
int tree[2000010];

int query(int start, int end, int node, int left, int right) {
    if (start > right || end < left)
        return 0;
    
    if (left <= start && end <= right)
        return tree[node];
    
    int mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

int update(int start, int end, int node, int index) {
    if (index < start || index > end)
        return tree[node];

    if (start == end)
        return tree[node] = 1;
        
    int mid = (start + end) / 2;
    return tree[node] = update(start, mid, node * 2, index) + update(mid + 1, end, node * 2 + 1, index);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    
    sort(arr, arr + n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += query(0, n - 1, 1, arr[i].second, n - 1);
        update(0, n - 1, 1, arr[i].second);
    }

    cout << ans;
}