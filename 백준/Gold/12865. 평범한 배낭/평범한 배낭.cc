#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> weight;
vector<int> value;

int Knapsack(int n, int k);

int main() {
    int n, k;
    cin >> n >> k;

    weight.resize(n+1); value.resize(n+1);
    for (int i=1; i<n+1; i++)
        cin >> weight[i] >> value[i];

    cout << Knapsack(n, k);
}

int Knapsack(int n, int k) {
    int dp[n+1][k+1];
    for (int i=0; i<=n; i++)
        dp[i][0] = 0;
    for (int j=0; j<=k; j++)
        dp[0][j] = 0;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            if (weight[i] <= j)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][k];
}