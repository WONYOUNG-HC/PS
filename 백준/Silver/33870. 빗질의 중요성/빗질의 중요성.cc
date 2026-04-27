#include <iostream>

using namespace std;

int n, m;
int arr[110];
int last[110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int prev_k;

    for (int i = 1; i <= m; i++) {
        int k;

        cin >> k;

        if (i - last[k] <= arr[k]) {
            last[k] = i;
        } else if (prev_k == k) {
            last[k] = i;
        }

        prev_k = k;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (m + 1 - last[i] > arr[i]) {
            ans += 1;
        }
    }

    cout << ans;
}