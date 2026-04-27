#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n; cin >> n;

    int arr[n];
    for (int& x : arr) cin >> x;

    sort(arr, arr + n, greater<>());
    n = min(n, 42);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 60) ans++;
        if (arr[i] >= 100) ans++;
        if (arr[i] >= 140) ans++;
        if (arr[i] >= 200) ans++;
        if (arr[i] >= 250) ans++;
    }

    cout << accumulate(arr, arr + n, 0) << ' ' << ans;
}