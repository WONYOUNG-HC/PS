#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
int arr[10010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    //
    //
    //

    ll answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll lower = lower_bound(arr + j + 1, arr + n, -(arr[i] + arr[j])) - arr;
            ll upper = upper_bound(arr + j + 1, arr + n, -(arr[i] + arr[j])) - arr;

            answer += upper - lower;
        }
    }

    cout << answer;
}