#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[100010];
bool vis[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> arr[i];

    int left = 0, right = 100000;
    while (left <= right) {
        int mid = (left + right) / 2;

        fill(vis, vis + 100010, false);
        for (int i = 0; i < m; i++) {
            for (int j = max(0, arr[i] - mid); j < min(n, arr[i] + mid); j++) {
                vis[j] = true;
            }
        }

        auto p = find(vis, vis + n, false);
        if (p == vis + n) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << left;
}