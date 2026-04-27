#include <iostream>
#include <array>

#define Sarray array<array<Shark *, 110>, 110>

using namespace std;

int r, c, m;
struct Shark {
    int s, d, z;

    Shark(int _s, int _d, int _z) : d(_d), z(_z) {
        int len = (_d < 3 ? r : c);
        s = _s % (len * 2 - 2);
    }
};

Sarray arr;
int dir[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> m;
    for (int i = 0; i < m; i++) {
        int y, x, s, d, z;
        cin >> y >> x >> s >> d >> z;
        arr[y][x] = new Shark(s, d, z);
    }

    int ans = 0;
    for (int pos = 1; pos <= c; pos++) {
        for (int j = 1; j <= r; j++) {
            if (arr[j][pos]) {
                ans += arr[j][pos]->z;
                delete arr[j][pos];
                arr[j][pos] = nullptr;
                break;
            }
        }

        Sarray narr{};
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (arr[i][j]) {
                    int y = i, x = j;
                    for (int k = 0; k < arr[i][j]->s; k++) {
                        y += dir[arr[i][j]->d][0];
                        x += dir[arr[i][j]->d][1];

                        if (y < 1 || y > r || x < 1 || x > c) {
                            arr[i][j]->d = arr[i][j]->d % 2 + (arr[i][j]->d < 3 ? 1 : 3);
                            k -= 2;
                            continue;
                        }
                    }

                    if (narr[y][x] && narr[y][x]->z > arr[i][j]->z) {
                        delete arr[i][j];
                        arr[i][j] = nullptr;
                    }
                    else {
                        delete narr[y][x];
                        narr[y][x] = arr[i][j];
                    }
                }
            }
        }

        swap(arr, narr);
    }

    cout << ans;
}