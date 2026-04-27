#include <iostream>

#define ll long long

using namespace std;

int n;
ll arr[200010], n0[200010], n1[200010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 0) n0[i] = 1;
        else if (arr[i] == 1) n1[i] = 1;

        n0[i] += n0[i + 1], n1[i] += n1[i + 1];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            ans += n - (i + 1) + n1[i];
        else
            ans += n0[i];

        if (arr[i] == 1)
            ans += n0[i];
    }

    cout << ans;
}