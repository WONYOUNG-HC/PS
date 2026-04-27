#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const double INF = 1000000.0;
int n;
double w[16][16];

double Travel();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    pair<int, int> pos[n];
    for (int i=0; i<n; i++)
        cin >> pos[i].first >> pos[i].second;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j)
                w[i][j] = INF;
            else
                w[i][j] = sqrt(pow(pos[i].first-pos[j].first, 2) + pow(pos[i].second-pos[j].second, 2));
        }
    }

    cout << fixed;
    cout << Travel();
}

void GetA(vector<vector<int>>& a_vec, int col) {
    int cnt, bit;
    for (int i=0; i<col; i++) {
        cnt = 0; bit = 1;
        for (int j=0; j<n-1; j++) {
            if (i & bit)
                cnt++;
            bit <<= 1;
        }

        a_vec[cnt].push_back(i);
    }
}

void GetIAndJ(vector<int>& i_vec, vector<int>& j_vec, int a) {
    int bit = 1;
    for (int i=1; i<n; i++) {
        if (a & bit)
            j_vec.push_back(i);
        else
            i_vec.push_back(i);

        bit <<= 1;
    }
}

double Travel() {
    int col = (int)pow(2, n-1) - 1;
    double dp[n][col];

    for (int i=1; i<n; i++)
        dp[i][0] = w[i][0];

    vector<vector<int>> a_vec(n-1);
    GetA(a_vec, col);
    for (int k=1; k<=n-2; k++) {
        for (int a : a_vec[k]) {
            vector<int> i_vec, j_vec;
            GetIAndJ(i_vec, j_vec, a);
            for (int i : i_vec) {
                dp[i][a] = INF;
                for (int j : j_vec) {
                    dp[i][a] = min(dp[i][a], w[i][j] + dp[j][a^(1<<(j-1))]);
                }
            }
        }
    }

    double length = INF;
    vector<int> _, j_vec;
    GetIAndJ(_, j_vec, col);
    for (int j : j_vec)
        length = min(length, w[0][j] + dp[j][col^(1<<(j-1))]);

    return length;
}