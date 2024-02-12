#include <iostream>

using namespace std;

int arr[11][11], cnt[6];
int ans = 1e9;

bool cover(int y, int x, int k) {
    for (int i = y; i < y + k; i++) {
        if (i > 9)
            return false;

        for (int j = x; j < x + k; j++) {
            if (j > 9)
                return false;

            if (arr[i][j] == 0)
                return false;
        }
    }

    return true;
}

void recur(int y, int x) {
    for (int i = 1; i <= 5; i++) {
        if (cnt[i] > 5) 
            return;
    }
    
    for (int i = y; i < 10; i++) {
        for (int j = (i == y ? x : 0); j < 10; j++) {
            if (arr[i][j] == 1) {
                for (int k = 1; k <= 5; k++) {
                    if (cover(i, j, k)) {
                        for (int u = i; u < i + k; u++) 
                            for (int v = j; v < j + k; v++) 
                                arr[u][v] = 0;
                        cnt[k]++;

                        recur(i, j);

                        cnt[k]--;
                        for (int u = i; u < i + k; u++)
                            for (int v = j; v < j + k; v++)
                                arr[u][v] = 1;
                    }
                }

                return;
            }
        }
    }

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (arr[i][j] == 1)
                return;
    
    int tot = 0;
    for (int i = 1; i <= 5; i++)
        tot += cnt[i];
    ans = min(ans, tot);
}

int main() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> arr[i][j];

    recur(0, 0);

    cout << (ans == 1e9 ? -1 : ans);
}