#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[210];
int dp[210];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << n - *max_element(dp, dp + n);
}