#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, b, c;
double arr[1'000'010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> b >> c;

    long long ans = n;
    for (int i = 0; i < n; i++)
        ans += max(0, (int)ceil((arr[i] - b) / c));

    cout << ans;
}