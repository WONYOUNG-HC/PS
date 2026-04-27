#include <iostream>
#include <algorithm>

using namespace std;

bool green[6][4];
bool blue[6][4];
int ans;

void prt(bool (*arr)[4]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void set_block(int t, int y, int x) {
    if (t == 1) {
        green[1][x] = true;

        blue[1][3 - y] = true;
    } else if (t == 2) {
        green[1][x] = true;
        green[1][x + 1] = true;

        blue[0][3 - y] = true;
        blue[1][3 - y] = true;
    } else if (t == 3) {
        green[0][x] = true;
        green[1][x] = true;

        blue[1][3 - y] = true;
        blue[1][3 - y - 1] = true;
    }
}

void block_down(bool (*arr)[4], int start, int end) {
    for (int i = 1; i < 5; i++) {
        bool is_down = true;

        for (int j = start; j < end; j++) {
            if (arr[i][j] && arr[i + 1][j]) {
                is_down = false;
            }
        }

        if (!is_down) {
            break;
        }

        for (int j = start; j < end; j++) {
            if (arr[i][j]) {
                arr[i + 1][j] = true;
                arr[i][j] = arr[i - 1][j];
                arr[i - 1][j] = false;
            }
        }
    }
}

void scoring(bool (*arr)[4]) {
    for (int i = 2; i < 6; i++) {
        if (count(arr[i], arr[i] + 4, true) == 4) {
            ans += 1;

            fill(arr[i], arr[i] + 4, false);

            for (int ii = i; ii > 0; ii--) {
                for (int j = 0; j < 4; j++) {
                    arr[ii][j] = arr[ii - 1][j];
                    arr[ii - 1][j] = false;
                }
            }
        }
    }
}

void clear_upper(bool (*arr)[4]) {
    int cnt = (bool)count(arr[0], arr[0] + 4, true) + (bool)count(arr[1], arr[1] + 4, true);

    while (cnt--) {
        for (int i = 4; i >= 0; i--) {
            for (int j = 0; j < 4; j++) {
                arr[i + 1][j] = arr[i][j];
                arr[i][j] = false;
            }
        }
    }
}

int count_block(bool (*arr)[4]) {
    int ret = 0;

    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            ret += arr[i][j];
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    while (tc--) {
        int t, y, x;

        cin >> t >> y >> x;

        set_block(t, y, x);

        int green_start = x;
        int green_end = (t == 2 ? x + 2 : x + 1);
        int blue_start = (t == 3 ? 3 - y - 1 : 3 - y);
        int blue_end = 3 - y + 1;
        
        block_down(green, green_start, green_end);
        block_down(blue, blue_start, blue_end);



        scoring(green);
        scoring(blue);

        clear_upper(green);
        clear_upper(blue);
    }

    cout << ans << '\n' << count_block(green) + count_block(blue);
}