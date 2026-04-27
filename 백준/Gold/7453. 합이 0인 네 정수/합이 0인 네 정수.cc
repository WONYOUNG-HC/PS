#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
int arr[4][4010];
int sum1[4010 * 4010], sum2[4010 * 4010];
ll ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[j][i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum1[i * n + j] = arr[0][i] + arr[1][j];
            sum2[i * n + j] = arr[2][i] + arr[3][j]; 
        }
    }

    sort(sum2, sum2 + n * n);

    for (int i = 0; i < n * n; i++) {
        ans += upper_bound(sum2, sum2 + n * n, -sum1[i]) - lower_bound(sum2, sum2 + n * n, -sum1[i]);
    }

    cout << ans;
}