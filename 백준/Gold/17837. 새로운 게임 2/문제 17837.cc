#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum DIRECTION {RIGHT = 1, LEFT, UP, DOWN};
enum COLOR {WHITE, RED, BLUE};

struct block {
    int color;
    vector<int> pieces;

    block() {
        color = BLUE;
    }
};

struct piece {
    int y, x, d;
};

int n, k;
block board[15][15];
piece arr[15];
int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            cin >> board[i][j].color;
        
    for (int i = 0; i < k; i++) {
        cin >> arr[i].y >> arr[i].x >> arr[i].d;
        board[arr[i].y][arr[i].x].pieces.push_back(i);
    }

    int ans = 1;
    while (ans <= 1000) {
        for (int i = 0; i < k; i++) {
            int y = arr[i].y, x = arr[i].x;

            int vi = 0;
            while (board[y][x].pieces[vi] != i) 
                vi++;
            
            vector<int> v {board[y][x].pieces.begin() + vi, board[y][x].pieces.end()};
            while (vi < board[y][x].pieces.size())
                board[y][x].pieces.pop_back();

            int ny = y + dir[arr[i].d][0], nx = x + dir[arr[i].d][1];
            
            if (board[ny][nx].color == BLUE) {
                arr[i].d += (arr[i].d % 2 ? 1 : -1);
                ny = y + dir[arr[i].d][0], nx = x + dir[arr[i].d][1];

                if (board[ny][nx].color == BLUE) {
                    for (int p : v) 
                        board[y][x].pieces.push_back(p);
                    
                    continue;
                }
            }

            if (board[ny][nx].color == RED) {
                reverse(v.begin(), v.end());
                for (int p : v) {
                    board[ny][nx].pieces.push_back(p);
                    arr[p].y = ny, arr[p].x = nx;
                }
            }
            else {
                for (int p : v) {
                    board[ny][nx].pieces.push_back(p);
                    arr[p].y = ny, arr[p].x = nx;
                }
            }

            if (board[ny][nx].pieces.size() >= 4) {
                cout << ans;
                return 0;
            }
        }

        ans++;
    }

    cout << -1;
}