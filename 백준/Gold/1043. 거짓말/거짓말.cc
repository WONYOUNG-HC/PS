#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool vis[55];
bool adj[55][55];
vector<int> arr[55];

void dfs(int x) {
    for (int i = 1; i <= n; i++) {
        if (adj[x][i] && !vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> m;
    
    int l; cin >> l;
    for (int i = 0; i < l; i++) {
        int a; cin >> a;
        vis[a] = true;
    }

    for (int i = 0; i < m; i++) {
        int p; cin >> p;
        
        auto &v = arr[i];
        for (int j = 0; j < p; j++) {
            int a; cin >> a;
            v.push_back(a);
        }

        for (int j = 0; j < p; j++) {
            for (int k = 0; k < p; k++) {
                adj[v[j]][v[k]] = true;
                adj[v[k]][v[j]] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            dfs(i);
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        bool flag = true;
        for (int x : arr[i]) {
            if (vis[x]) {
                flag = false;
                break;
            }
        }

        flag && ans++;
    }

    cout << ans;
}