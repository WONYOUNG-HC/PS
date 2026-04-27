#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const ll inf = 1e12;

int n;
ll arr[100010][5];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int tc = 1; ; tc++) {
        cin >> n;

        if (n == 0) {
            break;
        }

        fill_n(&arr[0][0], 100010 * 5, inf);

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= 3; j++) {
                cin >> arr[i][j];
            }
        }
        
        arr[0][3] += arr[0][2];
        arr[0][1] = inf;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= 3; j++) {
                ll mn = inf;

                mn = min(mn, arr[i - 1][j - 1]);
                mn = min(mn, arr[i - 1][j]);
                mn = min(mn, arr[i - 1][j + 1]);
                mn = min(mn, arr[i][j - 1]);

                arr[i][j] += mn;
            }
        }

        cout << tc << ". " << arr[n - 1][2] << '\n';
    }
}