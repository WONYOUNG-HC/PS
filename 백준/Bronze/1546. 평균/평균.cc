#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n; cin >> n;

    double arr[n], mx = 0;
    for (double& x : arr) cin >> x, mx = max(mx, x);

    for (int i = 0; i < n; i++)
        arr[i] = arr[i] / mx * 100;

    printf("%.3lf", accumulate(arr, arr + n, 0.0) / n);
}