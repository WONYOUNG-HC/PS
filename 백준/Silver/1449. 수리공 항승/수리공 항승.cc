#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    cin >> n >> l;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int ans = 0, prev = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] - prev >= l) {
            ans++;
            prev = arr[i];
        }
    }

    cout << ans + 1;
}