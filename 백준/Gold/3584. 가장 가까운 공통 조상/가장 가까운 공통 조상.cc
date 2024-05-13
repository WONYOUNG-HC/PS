#include <iostream>
#include <algorithm>

using namespace std;

int n;
int parent[10010];
bool vis[10010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        cin >> n;
        
        int a, b;
        fill(parent, parent + n + 10, -1);
        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            parent[b] = a;
        }

        cin >> a >> b;

        fill(vis, vis + n + 10, false);
        int cur = a;
        do {
            vis[cur] = true;
            cur = parent[cur];
        } while (cur != -1);

        cur = b;
        while (!vis[cur]) {
            cur = parent[cur];
        }

        cout << cur << '\n';
    }
}