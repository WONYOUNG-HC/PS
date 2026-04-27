#include <iostream>

using namespace std;

int n, ans = 1e9, sum = 0;
int arr[21][21], acc[21][2];
bool team[21];
// index 0 is row major, index 1 is column major

void f(int cur, int cnt) {
    if (cnt == n / 2) {
        int a = sum, b = sum;

        for (int i = 0; i < n; i++) {
            if (team[i]) {
                b -= acc[i][0] + acc[i][1];
            }
            else {
                a -= acc[i][0] + acc[i][1];
            }
        }

        ans = min(ans, abs(a - b) / 2);

        return;
    }

    for (int i = cur; i < n; i++) {
        team[i] = true;
        f(i + 1, cnt + 1);
        team[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            acc[i][0] += arr[i][j];
            acc[j][1] += arr[i][j];
            sum += arr[i][j];
        }
    }

    f(0, 0);
    cout << ans;
}