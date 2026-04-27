#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;

    long long arr[n];
    for (long long& x : arr) cin >> x;

    sort(arr, arr + n, greater<>());

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] - i <= 0)
            break;

        sum += arr[i] - i;
    }

    cout << sum;
}