#include <iostream>
#include <map>

using namespace std;

int n, m;
int sum[1000010];
map<int, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int a;

        cin >> a;

        sum[i] = (sum[i - 1] + a) % m;
    }

    long long ans = 0;

    mp[0] = 1;

    for (int i = 1; i <= n; i++) {
        ans += mp[sum[i]];
        mp[sum[i]] += 1;
    }

    cout << ans;
}