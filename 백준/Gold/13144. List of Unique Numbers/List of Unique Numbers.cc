#include <iostream>

using namespace std;

int n;
int arr[100010];
bool vis[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //
    //
    //

    int left = 0;
    int right = 1;
    long long ans = 0;
    vis[arr[0]] = true;

    while (left < n) {
        while (right < n && !vis[arr[right]]) {
            vis[arr[right]] = true;
            right += 1;
        }

        ans += right - left;

        vis[arr[left]] = false;
        left += 1;
    }

    cout << ans;
}