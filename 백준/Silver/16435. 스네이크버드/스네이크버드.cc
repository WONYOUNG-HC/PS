#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    cin >> n >> l;

    int arr[n];
    for (int& x : arr) cin >> x;
    sort(arr, arr + n);

    for (int a : arr)
        a <= l && l++;

    cout << l;
}