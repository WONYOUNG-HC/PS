#include <iostream>
#include <algorithm>

using namespace std;

const int n = 2000000;
bool chk[n + 10];
vector<int> prime;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill_n(chk, n + 10, true);
    for (int i = 2; i * i <= n; i++) {
        if (!chk[i])
            continue;

        int j = i + i;
        while (j <= n) {
            chk[j] = false;
            j += i;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (chk[i])
            prime.push_back(i);
    }

    int tc; cin >> tc;
    while (tc--) {
        long long a, b;
        cin >> a >> b;

        bool ans = true;
        if ((a + b) % 2 != 0) {
            if (a + b - 2 < n) {
                ans = chk[a + b - 2];
            }
            else {
                for (int p : prime) {
                    if ((a + b - 2) % p == 0) {
                        ans = false;
                        break;
                    }
                }
            }
        }
        if (a + b == 2 || a + b == 3) {
            ans = false;
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
}