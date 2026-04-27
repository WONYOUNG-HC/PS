#include <iostream>

using namespace std;

int n, d, k, c;
int arr[30010];
int vis[3010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d >> k >> c;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //
    //
    //

    int ans = 0;
    int cnt = 0;
    bool bonus = false;

    int left = 0;
    int right = -1;

    for (int i = 0; i < k; i++) {
        right += 1;

        if (vis[arr[right]] == 0) {
            cnt += 1;
        }

        if (arr[right] == c) {
            bonus = true;
        }

        vis[arr[right]] += 1;
    }

    ans = cnt + !bonus;

    do {
        if (vis[arr[left]] == 1) {
            cnt -= 1;

            if (arr[left] == c) {
                bonus = false;
            }
        }

        vis[arr[left]] -= 1;
        left += 1;

        right = (right + 1) % n;
        vis[arr[right]] += 1;

        if (vis[arr[right]] == 1) {
            cnt += 1;

            if (arr[right] == c) {
                bonus = true;
            }
        }

        ans = max(ans, cnt + !bonus);
    } while (left < n);

    cout << ans;
}