#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, m;
pii a[110];
int b[110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;

        a[i].second = i;
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a, a + n, [](pii left, pii right) -> bool {
        if (left.first == right.first) {
            return left.second < right.second;
        }

        return left.first > right.first;
    });

    //
    //
    //

    vector<pii> ans;

    int bi = 0;

    for (int i = 0; i < n; i++) {
        if (!ans.empty() && ans.back().second > a[i].second) {
            continue;
        }

        int idx = find_if(b + bi, b + m, [i](int v) -> bool {
            return v == a[i].first;
        }) - b;

        if (idx == m) {
            continue;
        }

        ans.push_back(a[i]);
        bi = idx + 1;
    }

    cout << ans.size() << '\n';

    for (auto pr : ans) {
        cout << pr.first << ' ';
    }
}