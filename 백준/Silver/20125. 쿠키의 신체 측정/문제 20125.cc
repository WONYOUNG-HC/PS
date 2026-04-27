#include <iostream>

using namespace std;

int n;
char arr[1010][1010];
pair<int, int> heart;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == '_')
                continue;

            bool flag = true;
            int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (int *d : dir) {
                int dy = i + d[0];
                int dx = j + d[1];
 
                if (arr[dy][dx] != '*') {
                    flag = false;
                    break;
                }
            }
            
            if (flag)
                heart = {i, j};
        }
    }

    int ans[5]{};
    for (int i = 0; i < 2; i++) {
        int d = (i == 0 ? -1 : 1);
        int x = heart.second + d;
        while (arr[heart.first][x] == '*') {
            x += d;
        }

        ans[i] = abs(x - heart.second) - 1;
    }

    int y = heart.first + 1;
    while (arr[y][heart.second] == '*') {
        y += 1;
    }
    y--;
    ans[2] = y - heart.first;

    for (int i = 3; i < 5; i++) {
        int x = heart.second + (i == 3 ? -1 : 1);
        int ny = y + 1;
        while (arr[ny][x] == '*') {
            ny += 1;
        }

        ans[i] = ny - y - 1;
    }

    cout << heart.first << ' ' << heart.second << '\n';
    for (int x : ans)
        cout << x << ' ';
}