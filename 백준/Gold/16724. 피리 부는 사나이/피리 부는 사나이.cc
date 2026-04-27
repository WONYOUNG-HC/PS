#include <iostream>

using namespace std;

int n, m, ans;
char arr[1010][1010];
int vis[1010][1010];
bool safe[1010][1010];

void dfs(int y, int x) {
    int ny = y, nx = x;
    if (arr[y][x] == 'U') 
        ny -= 1;
    else if (arr[y][x] == 'D') 
        ny += 1;
    else if (arr[y][x] == 'L') 
        nx -= 1;
    else 
        nx += 1;

    if (vis[ny][nx] == 0) {
        vis[ny][nx] = 1;
        dfs(ny, nx);
        vis[ny][nx] = 2;
    }
    else if (vis[ny][nx] == 1) {
        ans++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if(vis[i][j] == 0)
                dfs(i, j);
    
    cout << ans;
}