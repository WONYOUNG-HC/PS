#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> invest;
vector<vector<int>> dp;
vector<vector<vector<int>>> divide;

int Knapsack(int money, int company);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    invest.resize(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        int in; cin >> in;

        for (int j = 1; j <= m; j++) {
            cin >> invest[in][j];
        }
    }

    dp.resize(n + 1, vector<int>(m + 1, -1));
    divide.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1)));

    cout << Knapsack(n, m) << '\n';
    for (int i = 1; i <= m; i++)
        cout << divide[n][m][i] << ' ';
}

int Knapsack(int money, int company) {
    if (dp[money][company] != -1)
        return dp[money][company];

    dp[money][company] = 0;

    if (money == 0 || company == 0)
        return dp[money][company];

    for (int i = money; i >= 0; i--) {
        int cost = Knapsack(money - i, company - 1) + invest[i][company];

        if (cost > dp[money][company]) {
            dp[money][company] = cost;
            divide[money][company] = divide[money - i][company - 1];
            divide[money][company][company] += i;
        }
    }

    return dp[money][company];
}