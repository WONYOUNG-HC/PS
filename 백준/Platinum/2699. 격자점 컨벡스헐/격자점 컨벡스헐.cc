#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
#define X first
#define Y second

using namespace std;

int n;
pii pos[55];

int ccw(pii a, pii b, pii c) {
    int ret = (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X);

    if (ret > 0) return 1;
    if (ret < 0) return -1;
    return 0;
}

bool compare(pii left, pii right) {
    int ret = ccw(pos[0], left, right);

    if (ret == 0) {
        if (left.Y == right.Y)
            return left.X < right.X;

        return left.Y > right.Y;
    }

    return ret < 0;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> pos[i].X >> pos[i].Y;

    for (int i = 1; i < n; i++) {
        if (pos[i].Y > pos[0].Y || (pos[i].Y == pos[0].Y && pos[i].X < pos[0].X))
            swap(pos[0], pos[i]);
    }

    sort(pos + 1, pos + n, compare);

    vector<pii> s = {pos[0], pos[1]};
    for (int i = 2; i < n; i++) {
        while (s.size() >= 2 && ccw(*(s.end() - 2), s.back(), pos[i]) >= 0)
            s.pop_back();
        s.push_back(pos[i]);
    }

    cout << s.size() << '\n';
    for (pii p : s)
        cout << p.X << ' ' << p.Y << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--)
        solve();
}