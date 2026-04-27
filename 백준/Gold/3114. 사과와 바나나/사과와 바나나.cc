#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int r, c;
vector<vector<int>> sum_apple;
vector<vector<int>> sum_banana;
vector<vector<int>> dp;

int Bulldozer(int y, int x);

int main() {
    scanf("%d %d", &r, &c);

    sum_apple.resize(r+1, vector<int>(c+1));
    sum_banana.resize(r+1, vector<int>(c+1));
    dp.resize(r+1, vector<int>(c+1, -1));

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            char fruit;
            int num, apple = 0, banana = 0;
            scanf(" %c%d", &fruit, &num);

            fruit == 'A' ? apple = num : banana = num;

            sum_apple[i][j] = (sum_apple[i][j-1] + apple);
            sum_banana[i][j] = (sum_banana[i-1][j] + banana);
        }
    }

    printf("%d", Bulldozer(1, 1));
}

int Bulldozer(int y, int x) {
    if (y == r && x == c)
        return 0;

    if (dp[y][x] != -1)
        return dp[y][x];

    if (y + 1 <= r)
        dp[y][x] = max(dp[y][x], Bulldozer(y+1, x) + sum_apple[y+1][x-1]);
    if (x + 1 <= c)
        dp[y][x] = max(dp[y][x], Bulldozer(y, x+1) + sum_banana[y-1][x+1]);
    if (y + 1 <= r && x + 1 <= c)
        dp[y][x] = max(dp[y][x], Bulldozer(y+1, x+1) + sum_apple[y+1][x] + sum_banana[y][x+1]);

    return dp[y][x];
}