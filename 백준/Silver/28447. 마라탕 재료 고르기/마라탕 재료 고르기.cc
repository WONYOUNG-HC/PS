#include <iostream>

using namespace std;

int n, k, ans = -1e9;
int arr[11][11];
bool vis[11];

void recur(int cnt, int pos) {
    if (cnt == k) {
        int cur = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (vis[i] && vis[j]) cur += arr[i][j];

        ans = max(ans, cur);
        return;
    }

    for (int i = pos; i < n; i++) {
        vis[i] = true;
        recur(cnt + 1, i + 1);
        vis[i] = false;
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    recur(0, 0);
    cout << ans;
}