#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    map<long long, long long> m;
    for (int i = 0; i < n; i++) {
        long long card; cin >> card;
        auto pr = m.insert({card, 1});
        if (!pr.second)
            m[card]++;
    }

    pair<long long, long long> ans = {0, 0};
    for (auto& iter : m) {
        if (iter.second > ans.second)
            ans = iter;
        if (iter.second == ans.second && iter.first < ans.first)
            ans = iter;
    }

    cout << ans.first;
}