#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int& x : arr) cin >> x;

    sort(arr, arr + n);

    int i = 0, j = n - 1;
    while (arr[i] + arr[j] > k) j--;

    int ans = 0;
    while (i < j) {
        if (arr[i] + arr[j] <= k)
            ans++, i++;
        j--;
    }

    cout << ans;
}