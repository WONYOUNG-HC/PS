#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[20010], b[20010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> m;
        
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        
        sort(b, b + m);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += lower_bound(b, b + m, a[i]) - b;
        }

        cout << ans << '\n';
    }
}