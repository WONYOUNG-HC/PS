#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define L first
#define R second
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<long long> v(n);

    for (long long& x : v) cin >> x;
    sort(v.begin(), v.end());

    vector<pair<long long, long long>> line(n);
    line[0].R = accumulate(v.begin(), v.end(), -v[0] * n);

    for (int i = 1; i < n; i++) {
        line[i].L = line[i - 1].L + (v[i] - v[i - 1]) * i;
        line[i].R = line[i - 1].R - (v[i] - v[i - 1]) * (n - i);
    }

    long long dist = 1e18, ans;
    for (int i = 0; i < n; i++) {
        if (line[i].L + line[i].R < dist) {
            dist = line[i].L + line[i].R;
            ans = v[i];
        }
    }

    cout << ans;
}