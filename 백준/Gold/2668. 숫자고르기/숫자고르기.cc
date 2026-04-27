#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n;
int arr[110];
bool vis[110];
set<int> ans;

void dfs(int src, int cur) {
    if (vis[cur]) {
        if (cur == src) {
            ans.insert(cur);
        }

        return;
    }

    vis[cur] = true;
    dfs(src, arr[cur]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        fill(vis, vis + n + 10, false);
        
        dfs(i, i);
    }

    cout << ans.size() << '\n';
    
    for (int a : ans) {
        cout << a << '\n';
    }
}