#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    string s[n];
    for (auto& x : s) cin >> x;

    long long arr[n];
    for (int i = 0; i < n; i++) {
        reverse(s[i].begin(), s[i].end());
        arr[i] = stoll(s[i]);
    }

    sort(arr, arr + n);
    for (auto x : arr)
        cout << x << '\n';
}