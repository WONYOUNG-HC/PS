#include <iostream>

using namespace std;

int n;
int arr[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0;
    int right = n - 1;
    int ans = 2e9;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(ans)) {
            ans = sum;
        }

        if (sum < 0) {
            left += 1;
        } else if (sum > 0) {
            right -= 1;
        } else {
            break;
        }
    }

    cout << ans;
}