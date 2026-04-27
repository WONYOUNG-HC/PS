#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[20][20];
int dp[20][20];
int dir[3][2] = {{0, 1}, {1, 1}, {1, 0}};

bool chk(int y, int x, int k) {
    for (int i = 0; i < 3; i++) {
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];

        if (i == k && arr[ny][nx] == 1)
            return false;
        
        if (k == 1 && arr[ny][nx] == 1)
            return false;
    }

    return true;
}

void dfs(int y, int x, int k) {
    dp[y][x] += 1;
   
    if (y == n && x == n)
        return;

    for (int i = 0; i < 3; i++) {
        if (abs(i - k) == 2)
            continue;

        if (chk(y, x, i)) {
            int dy = y + dir[i][0];
            int dx = x + dir[i][1];

            dfs(dy, dx, i);
        }
    }
}

int main() {
    cin >> n;    
    
    fill_n(&arr[0][0], 20 * 20, 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    dfs(1, 2, 0);
    cout << dp[n][n];
}