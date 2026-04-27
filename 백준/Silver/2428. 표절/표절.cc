#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int j = lower_bound(arr, arr + i, arr[i] * 0.9) - arr;
        ans += i - j;
    }

    cout << ans;
}