#include <iostream>
#include <algorithm>

#define X first
#define Y second

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int n;
pll arr[55];
int ans[55];

ll ccw(pll a, pll b, pll c) {
    return (a.X - c.X) * (b.Y - c.Y) - (b.X - c.X) * (a.Y - c.Y);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        arr[i].X = i;
        cin >> arr[i].Y;
    }

    for (int i = 0; i < n; i++) {
        ans[i] = 2;
        i == 0 && ans[i]--;
        i == n - 1 && ans[i]--;

        for (int j = 0; j < i - 1; j++) {
            bool flag = false;
                
            for (int k = j + 1; k < i; k++) {
                flag = true;
                if (ccw(arr[i], arr[j], arr[k]) <= 0) {
                    flag = false;
                    break;
                }
            }

            flag && ans[i]++;
        }

        for (int j = i + 2; j < n; j++) {
            bool flag = false;

            for (int k = i + 1; k < j; k++) {
                flag = true;
                if (ccw(arr[i], arr[j], arr[k]) >= 0) {
                    flag = false;
                    break;
                }
            }

            flag && ans[i]++;
        }
    }

    cout << *max_element(ans, ans + n);
}