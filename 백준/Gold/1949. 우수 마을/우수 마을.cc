#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[10010];
vector<int> tree[10010];
bool vis[10010];
int dp[10010][2];

void dfs(int node) {
    vis[node] = true;
    
    dp[node][0] = 0;
    dp[node][1] = arr[node];

    for (int next : tree[node]) {
        if (!vis[next]) {
            dfs(next);

            dp[node][0] += max(dp[next][1], dp[next][0]);
            dp[node][1] += dp[next][0];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;

        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);

    cout << max(dp[1][0], dp[1][1]);
}