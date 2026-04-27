#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<int> adj[2010];
int arr[55], match[2010];
bool vis[2010], prime[2010];
vector<int> ans;

bool dfs(int x) {
    if (vis[x])
        return false;
    vis[x] = true;

    for (int y : adj[x]) {
        if (match[y] == 0 || dfs(match[y])) {
            match[y] = x;
            return true;
        }
    }

    return false;
}

void eratosthenes() {
    fill(prime, prime + 2010, true);
    prime[1] = false;

    for (int i = 2; i <= sqrt(2000); i++) {
        if (!prime[i])
            continue;

        int j = i + i;
        while (j <= 2000) {
            prime[j] = false;
            j += i;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    eratosthenes();

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (prime[arr[i] + arr[j]]) {
                adj[arr[i]].push_back(arr[j]);
                adj[arr[j]].push_back(arr[i]);
            }
        }
    }

    for (int k : adj[arr[0]]) {
        fill(match, match + 2010, 0);
        match[k] = arr[0];

        int cnt = 1;
        for (int i = 1; i < n; i++) {
            fill(vis, vis + 2010, false);
            vis[arr[0]] = true;

            if (dfs(arr[i]))
                cnt++;
        }

        if (cnt == n)
            ans.push_back(k);
    }

    sort(ans.begin(), ans.end());

    if (ans.empty())
        cout << -1;

    for (int x : ans)
        cout << x << ' ';
}