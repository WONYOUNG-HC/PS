#include <iostream>
#include <numeric>

using namespace std;

int n, s, ans;
int arr[30], seq[30];

void dfs(int cur, int cnt, int len) {
    if (cnt == len) {
        accumulate(seq, seq + len, 0) == s && ans++;
        return;
    }

    for (int i = cur; i < n; i++) {
        seq[cnt] = arr[i];
        dfs(i + 1, cnt + 1, len);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++)
        dfs(0, 0, i);

    cout << ans;
}