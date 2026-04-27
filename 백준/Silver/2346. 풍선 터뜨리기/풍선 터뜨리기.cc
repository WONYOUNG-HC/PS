#include <iostream>

using namespace std;

int n;
int arr[1010];
bool vis[1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int cur = 0;
    for (int i = 0; i < n - 1; i++) {
        cout << cur + 1 << ' ';
        vis[cur] = true;
        int cnt = 0, idx = cur, dir = (arr[cur] > 0 ? 1 : -1);

        while (cnt < abs(arr[cur])) {
            idx = (idx + dir) % n;

            if (idx < 0)
                idx = n - 1;

            !vis[idx] && cnt++;
        }

        cur = idx;
    }

    cout << cur + 1;
}