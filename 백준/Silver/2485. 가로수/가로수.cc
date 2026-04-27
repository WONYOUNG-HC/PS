#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100010], diff[100010];

int gcd(int a, int b) {
    if (b == 0) 
        return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n - 1; i++)
        diff[i] = arr[i + 1] - arr[i];

    int k = 0;
    for (int i = 0; i < n - 1; i++) 
        k = gcd(diff[i], k);

    int mx = *max_element(arr, arr + n), mn = *min_element(arr, arr + n);
    cout << (mx - mn) / k - (n - 1);
}