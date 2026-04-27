#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int t;

        cin >> t;

        map<ll, ll> mp;

        for (int j = 0; j < t; j++) {
            ll k;

            cin >> k;

            mp[k] += 1;
        }

        vector<pair<ll, ll>> v;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            v.push_back({it->second, it->first});
        }

        sort(v.begin(), v.end(), greater<pair<ll, ll>>());

        if (v[0].first <= t / 2) {
            cout << "SYJKGW\n";
        } else if (v.size() >= 2 && v[0].first == v[1].first) {
            cout << "SYJKGW\n";
        } else {
            cout << v[0].second << '\n';
        }
    }
}