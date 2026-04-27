#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct query {
    int a, b, c;
};

int n, q;
int adj[200010];
query arr[400010];
vector<bool> ans;
int parent[200010], level[200010];

int find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (level[y] > level[x])
        swap(x, y);
    
    parent[y] = x;
    if (level[x] == level[y])
        level[x]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int a; cin >> a;
        adj[i] = a;
    }

    for (int i = 0; i < q + n - 1; i++) {
        cin >> arr[i].a >> arr[i].b;
        if (arr[i].a == 1) cin >> arr[i].c;
    }

    reverse(arr, arr + q + n - 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i, level[i] = 1;
    
    for (int i = 0; i < q + n - 1; i++) {
        if (arr[i].a == 0) 
            merge(arr[i].b, adj[arr[i].b]);
        else 
            ans.push_back(find(arr[i].b) == find(arr[i].c));
    }

    reverse(ans.begin(), ans.end());
    for (bool b : ans)
        cout << (b ? "YES" : "NO") << '\n';
}