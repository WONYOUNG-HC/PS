#include <iostream>
#include <string>

using namespace std;

int n;
string mv; 
char arr[200][200];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    cin >> n >> mv;

    int y = 100, x = 100;
    int d = 0;
    arr[y][x] = '.';
    for (char c : mv) {
        if (c == 'L') {
            d = (d + 1) % 4;
        }
        else if (c == 'R') {
            d = (d + 3) % 4;
        }
        else {
            y += dir[d][0];
            x += dir[d][1];
            arr[y][x] = '.';
        }
    }    

    int y1 = 1000, x1 = 1000, y2 = -1, x2 = -1;
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            if (arr[i][j]) {
                y1 = min(y1, i), x1 = min(x1, j);
                y2 = max(y2, i), x2 = max(x2, j);
            }
        }
    }

    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            cout << (arr[i][j] ? '.' : '#');
        }
        cout << '\n';
    }
}
