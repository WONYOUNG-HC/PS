#include <iostream>
#include <map>

using namespace std;

int n, c;
int arr[40];
map<int, int> mp_a, mp_b, acc_a;
long long ans = 0;

void f(int end, int cur, int sum, map<int, int> &mp, bool right) {
    if (cur == end) {
        return;
    }

    f(end, cur + 1, sum, mp, right);

    if (sum + arr[cur] > c) {
        return;
    }

    mp[sum + arr[cur]] += 1;

    if (right) {
        auto it = acc_a.lower_bound(c - (sum + arr[cur]));

        if (it == acc_a.end() || it->first > (c - (sum + arr[cur]))) {
            it--;
        } 

        ans += it->second;
    }

    f(end, cur + 1, sum + arr[cur], mp, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mp_a[0] = 1;
    f(n / 2, 0, 0, mp_a, false);

    acc_a[0] = 0;

    for (auto it : mp_a) {
        acc_a[it.first] = acc_a.rbegin()->second + it.second;
    }

    mp_b[0] = 1;
    ans += acc_a.rbegin()->second;

    f(n, n / 2, 0, mp_b, true);

    cout << ans;
}