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

    int dif = 2e9 + 10;
    pair<int, int> ans;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(arr, arr + n, -arr[i]) - arr;
        if (idx < n && idx != i && dif > abs(arr[i] + arr[idx])) {
            dif = abs(arr[i] + arr[idx]);
            ans.first = min(arr[i], arr[idx]);
            ans.second = max(arr[i], arr[idx]);
        }
        if (idx > 0 && idx - 1 != i && dif > abs(arr[i] + arr[idx - 1])) {
            dif = abs(arr[i] + arr[idx - 1]);
            ans.first = min(arr[i], arr[idx - 1]);
            ans.second = max(arr[i], arr[idx - 1]);
        }
    }

    cout << ans.first << ' ' << ans.second;
}