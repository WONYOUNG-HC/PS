#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
char arr[1005][55];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    char h[55];
    for (int i = 0; i < m; i++) {
        int cnt[26]{0};

        for (int j = 0; j < n; j++)
            cnt[arr[j][i] - 'A']++;

        h[i] = (max_element(cnt, cnt + 26) - cnt) + 'A';
    }
    h[m] = '\0';

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] != h[j]) ans++;

    cout << h << '\n' << ans;
}