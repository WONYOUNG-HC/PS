#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int r = 12, c = 6;
char arr[20][10];
bool vis[20][10];
vector<pair<int, int>> bomb;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int y, int x, char color, vector<pair<int, int>> &trace) {
    vis[y][x] = true;
    trace.emplace_back(y, x);

    bool ret = false;
    for (int *d : dir) {
        int dy = y + d[0];
        int dx = x + d[1];

        if (arr[dy][dx] != color || vis[dy][dx])
            continue;

        dfs(dy, dx, color, trace);
    }
}

int main() {
    fill_n(&arr[0][0], 200, 'X');
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> arr[i][j];
    
    int ans = 0;
    while (true) {
        fill_n(&vis[0][0], 200, false);
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (vis[i][j] || arr[i][j] == '.')
                    continue;

                vector<pair<int, int>> trace;
                dfs(i, j, arr[i][j], trace);

                if (trace.size() < 4)
                    continue;
        
                for (auto pr : trace)
                    bomb.push_back(pr);
            }
        }

        if (bomb.empty())
            break;

        for (auto pr : bomb) 
            arr[pr.first][pr.second] = '.';
        bomb.clear();

        for (int j = 1; j <= c; j++) {
            for (int i = 11; i > 0; i--) {
                if (!(arr[i][j] != '.' && arr[i + 1][j] == '.'))
                    continue;
                
                int ni = i + 1;
                while (arr[ni][j] == '.') {
                    swap(arr[ni - 1][j], arr[ni][j]);
                    ni++;
                }
            }
        }

        ans++;
    }

    cout << ans;
}