#include <iostream>
#include <vector>

using namespace std;

struct Fire {
    int r, c, m, s, d;

    Fire() {
        r = c = m = s = d = 0;
    };

    Fire(int r, int c, int m, int s, int d) : r(r), c(c), m(m), s(s), d(d) {};
};

int n, m, k;
vector<Fire> arr[60][60];
int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int r, c, m, s, d;

        cin >> r >> c >> m >> s >> d;

        arr[r][c].emplace_back(r, c, m, s, d);
    }

    //
    //
    //

    while (k--) {
        vector<Fire> fires;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (Fire f : arr[i][j]) {
                    if (f.m > 0) {
                        fires.push_back(f);
                    }
                }
            
                arr[i][j].clear();
            }
        }

        for (Fire f : fires) {
            int *d = dir[f.d];

            for (int i = 0; i < f.s % n; i++) {
                f.r = (f.r + d[0] + n - 1) % n + 1;
                f.c = (f.c + d[1] + n - 1) % n + 1;
            }

            arr[f.r][f.c].push_back(f);
        }

        //
        //
        //

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j].size() < 2) {
                    continue;
                }

                Fire new_fire;
                int odd = 0;
                int even = 0;
                
                new_fire.r = i;
                new_fire.c = j;

                for (Fire f : arr[i][j]) {
                    new_fire.m += f.m;
                    new_fire.s += f.s;

                    even += f.d % 2 == 0;
                    odd += f.d % 2 == 1;
                }

                int cnt = arr[i][j].size();

                arr[i][j].clear();

                for (int l = 0; l < 4; l++) {
                    int r = i;
                    int c = j;
                    int m = new_fire.m / 5;
                    int s = new_fire.s / cnt;
                    int d = l * 2 + (even < cnt && odd < cnt);

                    arr[i][j].emplace_back(r, c, m, s, d);
                }   
            }
        }
    }

    //
    //
    //

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (Fire f : arr[i][j]) {
                ans += f.m;
            }
        } 
    }

    cout << ans;
}