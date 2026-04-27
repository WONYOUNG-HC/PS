#include <iostream>
#include <algorithm>

using namespace std;

struct edge {
    int a, b, c;
};

int m, n;
edge arr[200010];
int p[200010], r[200010];

int find(int x) {
    if (p[x] == x)
        return x;
    return p[x] = find(p[x]);
}

bool merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return false;

    if (r[v] > r[u])
        swap(u, v);
    
    p[v] = u;
    if (r[u] == r[v])  
        r[u]++;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> m >> n;

        if (m + n == 0)
            break;

        for (int i = 0; i < n; i++)
            cin >> arr[i].a >> arr[i].b >> arr[i].c;
        
        sort(arr, arr + n, [](const edge &left, const edge &right) -> bool {
            return left.c < right.c;
        });

        for (int i = 0; i < m; i++) {
            p[i] = i;
            r[i] = 1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) 
            !merge(arr[i].a, arr[i].b) && (ans += arr[i].c);
        
        cout << ans << '\n';
    }
}