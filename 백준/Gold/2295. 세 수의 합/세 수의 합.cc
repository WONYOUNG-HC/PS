#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;
using ll = long long;

int n;
ll arr[1010];
ll sum[1000010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int si = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            sum[si++] = arr[i] + arr[j];

    sort(arr, arr + n);
    sort(sum, sum + si);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            int k = lower_bound(sum, sum + si, arr[i] - arr[j]) - sum;

            if (sum[k] + arr[j] == arr[i]) {
                cout << arr[i];
                return 0;
            }
        }
    }

    assert(0);
}
