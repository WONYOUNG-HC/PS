#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int arr[10];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int ans = -1e9;

    do {
        int value = 0;

        for (int i = 1; i < n; i++) {
            value += abs(arr[i - 1] - arr[i]);
        }

        ans = max(ans, value);
    } while (next_permutation(arr, arr + n));

    cout << ans;
}
