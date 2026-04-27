#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> dp;

void Eratosthenes(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums;
    int n = -1;
    while (n != 0) {
        cin >> n;
        nums.push_back(n);
    }

    Eratosthenes(*max_element(nums.begin(), nums.end()-1));

    for (auto iter = nums.begin(); iter != nums.end() - 1; iter++) {
        cout << dp[(*iter)*2] - dp[(*iter)] << '\n';
    }
}

void Eratosthenes(int n) {
    vector<bool> prime_nums(n * 2 + 1, true);
    for (int i = 2; i <= sqrt(n*2); i++) {
        if (!prime_nums[i])
            continue;

        int j = i + i;
        while (j <= n * 2) {
            prime_nums[j] = false;
            j += i;
        }
    }

    dp.resize(n * 2 + 1);
    for (int i = 2; i <= n*2; i++) {
        dp[i] += dp[i-1];
        if (prime_nums[i]) dp[i]++;
    }
}