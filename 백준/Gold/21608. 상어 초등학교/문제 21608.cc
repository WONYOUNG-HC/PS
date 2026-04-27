#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n;
int arr[30][30];
int students[30 * 30];
bool prefer[30 * 30][30 * 30];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n * n; i++) {
        int a, b;

        cin >> a;

        students[i] = a;

        for (int j = 0; j < 4; j++) {
            cin >> b;

            prefer[a][b] = true;
        }
    }

    //
    //
    //

    fill_n(&arr[0][0], 30 * 30, -1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = 0;
        }
    }

    for (int k = 1; k <= n * n; k++) {
        int s = students[k];

        /// 
        //
        //

        int adj = 0;
        vector<pii> candidate;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] != 0) {
                    continue;
                }
                
                int cnt = 0;

                for (int *d : dir) {
                    int di = i + d[0];
                    int dj = j + d[1];

                    if (arr[di][dj] == -1) {
                        continue;
                    }

                    if (!prefer[s][arr[di][dj]]) {
                        continue;
                    }

                    cnt += 1;
                }

                if (cnt < adj) {
                    continue;
                }

                if (cnt > adj) {
                    candidate.clear();
                    adj = cnt;
                } 

                candidate.push_back({i, j});
            }
        }

        if (candidate.size() == 1) {
            arr[candidate[0].first][candidate[0].second] = s;

            continue;
        }

        //
        //
        //

        vector<pii> new_candidate;
        adj = 0;

        if (candidate.size() == 0) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    candidate.push_back({i, j});
                }
            }
        }

        for (auto pos : candidate) {
            int y, x;
            int cnt = 0;

            tie(y, x) = pos;

            for (int *d : dir) {
                int dy = y + d[0];
                int dx = x + d[1];

                if (arr[dy][dx] == 0) {
                    cnt += 1;
                }
            }

            if (cnt < adj) {
                continue;
            }

            if (cnt > adj) {
                new_candidate.clear();
                adj = cnt;
            }

            new_candidate.push_back({y, x});
        }

        sort(new_candidate.begin(), new_candidate.end());

        arr[new_candidate[0].first][new_candidate[0].second] = s;
    }

    //
    //
    //
    
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int cnt = 0;

            for (int *d : dir) {
                int di = i + d[0];
                int dj = j + d[1];

                if (arr[di][dj] == -1) {
                    continue;
                }

                if (prefer[arr[i][j]][arr[di][dj]]) {
                    cnt += 1;
                }
            }

            switch (cnt) {
                case 1:
                    ans += 1;
                    break;
                case 2:
                    ans += 10;
                    break;
                case 3:
                    ans += 100;
                    break;
                case 4:
                    ans += 1000;
                }
        }
    }

    cout << ans;
}