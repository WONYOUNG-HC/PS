#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1010];
int dp[1010];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        dp[i] = arr[i];
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }
    
    cout << *max_element(dp, dp + n);
}