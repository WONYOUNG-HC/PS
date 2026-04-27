#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> candies(100001);
vector<bool> prime_nums;

void Eratosthenes(int upper);
long long BuyCandy(int max_price, int upper);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int max_price = 0, upper = 0;
    for (int i=1; i<=n; i++) {
        int price; cin >> price;
        candies[price]++;
        upper += price;
        if (price > max_price) max_price = price;
    }

    Eratosthenes(upper);

    cout << BuyCandy(max_price, upper);
}

void Eratosthenes(int upper) {
    prime_nums.resize(upper + 1, true);

    for (int i = 2; i <= sqrt(upper); i++) {
        if (!prime_nums[i])
            continue;

        int j = i + i;
        while (j <= upper) {
            prime_nums[j] = false;
            j += i;
        }
    }
}

long long BuyCandy(int max_price, int upper) {
    vector<long long> dp(upper+1);
    dp[0] = 1;

    for (int i = max_price; i > 0; i--) {
        if (candies[i] == 0)
            continue;

        vector<int> v;
        for (int j = 1; j <= candies[i]; j++)
            v.push_back(i * j);

        for (int j = upper; j > 0; j--) {
            for (int price : v) {
                if (j - price >= 0)
                    dp[j] += dp[j - price];
            }
        }
    }

    long long ans = 0;
    for (int i = 2; i <= upper; i++) {
        if (prime_nums[i])
            ans += dp[i];
    }

    return ans * (candies[0] + 1);
}