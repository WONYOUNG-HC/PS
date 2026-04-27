#include <iostream>

using namespace std;

int n, k;
int plug[110], cnt[110], arr[110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> arr[i];

    int pi = 0, ans = 0;
    for (int i = 0; i < k; i++) {
        bool flag = false;
        for (int j = 0; j < pi; j++) {
            if (plug[j] == arr[i]) {
                flag = true;
                break;
            }
        }
        if (flag)
            continue;

        if (pi < n) {
            plug[pi++] = arr[i];
            continue;
        }

        for (int j = 0; j < n; j++) {
            for (int l = i + 1; l < k; l++) {
                if (arr[l] == plug[j]) {
                    cnt[j] = l;
                    break;
                }

                if (l == k - 1)
                    cnt[j] = 1000;
            }
        }

        int mx = 0;
        for (int j = 1; j < k; j++) {
            if (cnt[j] > cnt[mx])
                mx = j;
        }

        plug[mx] = arr[i];
        ans++;
    }

    cout << ans;
}