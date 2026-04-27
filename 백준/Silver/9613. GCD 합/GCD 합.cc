#include <iostream>

using namespace std;

int n, arr[110];

int gcd(int a, int b) {
    int r = a % b;
    if (r == 0)
        return b;

    return gcd(b, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        long long ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                ans += gcd(arr[i], arr[j]);

        cout << ans << '\n';
    }
}