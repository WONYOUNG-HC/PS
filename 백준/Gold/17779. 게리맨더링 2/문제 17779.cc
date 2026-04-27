#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int n;
int arr[30][30];
int area[30][30];
int cnt[10];

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    //
    //
    //

    int answer = 1e9;

    for (int x = 1; x < n; x++) {
        for (int y = 1; y < n; y++) {

            for (int d1 = 1; y - d1 >= 1; d1++) {
                for (int d2 = 1; x + d1 + d2 <= n && y + d2 <= n; d2++) {
                    int length[4] = {d1, d2, d2, d1};
                    int directoins[4][2] = {{1, -1}, {1, 1}, {1, 1}, {1, -1}};
                    int starts[4][2] = {{x, y}, {x, y}, {x + d1, y - d1}, {x + d2, y + d2}};

                    fill_n(&area[0][0], 30 * 30, 0);

                    for (int k = 0; k < 4; k++) {
                        int *dir = directoins[k];
                        int *start = starts[k];

                        int j = start[0];
                        int i = start[1];
                        
                        area[i][j] = 5;

                        for (int l = 0; l < length[k]; l++) {
                            j += dir[0];
                            i += dir[1];

                            area[i][j] = 5;
                        }
                    }

                    for (int i = y - d1 + 1; i <= y + d2 - 1; i++) {
                        int j = x;
                        
                        while (area[i][j++] != 5);

                        do {
                            area[i][j] = 5;
                        } while (area[i][++j] != 5);
                    }

                    //
                    //
                    //

                    for (int i = 1; i < y; i++) {
                        for (int j = 1; j <= x + d1; j++) {
                            if (area[i][j] != 0) {
                                break;
                            }

                            area[i][j] = 1;
                        }
                    }

                    for (int i = 1; i <= y - d1 + d2; i++) {
                        for (int j = n; j > x + d1; j--) {
                            if (area[i][j] != 0) {
                                break;
                            }

                            area[i][j] = 2;
                        }
                    }

                    for (int i = y; i <= n; i++) {
                        for (int j = 1; j < x + d2; j++) {
                            if (area[i][j] != 0) {
                                break;
                            }

                            area[i][j] = 3;
                        }
                    }

                    for (int i = y - d1 + d2 + 1; i <= n; i++) {
                        for (int j = n; j >= x + d2; j--) {
                            if (area[i][j] != 0) {
                                break;
                            }

                            area[i][j] = 4;
                        }
                    }

                    //
                    //
                    //
                
                    fill(cnt, cnt + 5, 0);

                    for (int i = 1; i <= n; i++) {
                        for (int j = 1; j <= n; j++) {
                            cnt[area[i][j] - 1] += arr[i][j];
                        }
                    }

                    int diff = *max_element(cnt, cnt + 5) - *min_element(cnt, cnt + 5);

                    answer = min(answer, diff);
                }
            }
        }
    }

    cout << answer;
}