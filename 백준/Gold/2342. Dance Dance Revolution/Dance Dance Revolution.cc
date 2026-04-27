#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int arr[100010];
int dp[100010][30];

int cost(int x, int y) {
    if (x == y) {
        return 1;
    }

    if (x == 0) {
        return 2;
    }

    if (abs(x - y) == 2) {
        return 4;
    }

    return 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; ; i++) {
        cin >> arr[i];

        n = i;

        if (arr[i] == 0) {
            break;
        }
    }

    fill_n(&dp[0][0], 100010 * 30, 1e9);

    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 25; j++) {
            int left = j / 5;
            int right = j % 5;

            int left_move_pos = arr[i] * 5 + right;
            int left_move_cost = dp[i][j] + cost(left, arr[i]);

            int right_move_pos = left * 5 + arr[i];
            int right_move_cost = dp[i][j] + cost(right, arr[i]);

            dp[i + 1][left_move_pos] = min(dp[i + 1][left_move_pos], left_move_cost);
            dp[i + 1][right_move_pos] = min(dp[i + 1][right_move_pos], right_move_cost);
        }
    }

    cout << *min_element(dp[n], dp[n] + 25);
}