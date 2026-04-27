#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int arr[100010];
int vis[1000010];
int result[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    fill_n(vis, 1000010, -1);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        vis[arr[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 2; arr[i] * j <= 1000000; j++) {
            if (vis[arr[i] * j] == -1) {
                continue;
            }

            result[vis[arr[i] * j]] -= 1;
            result[i] += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
}