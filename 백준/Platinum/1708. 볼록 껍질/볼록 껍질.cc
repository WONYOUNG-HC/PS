#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

struct pos {
    ll x, y;

    pos(ll x = 0, ll y = 0) : x(0), y(0) {}

    bool operator<(pos p) const {
        if (y == p.y) {
            return x < p.x;
        }

        return y < p.y;
    }
};

int n;
pos arr[100010];

ll ccw(pos a, pos b, pos c) {
    return ((a.x - b.x) * (b.y - c.y)) - ((a.y - b.y) * (b.x - c.x));
}

ll ccw(pos a, pos b, pos c, pos d) {
    pos u = {b.x - a.x, b.y - a.y};
    pos v = {d.x - c.x, d.y - c.y};

    return ccw({0, 0}, u, v);
}

ll dist(pos a, pos b) {
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;

    return (dx * dx) + (dy * dy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    //
    //
    //

    swap(arr[0], *min_element(arr, arr + n));

    sort(arr + 1, arr + n, [](pos a, pos b) -> bool {
        ll cw = ccw(arr[0], a, b);

        if (cw != 0) {
            return cw > 0;
        }

        return a < b;
    });

    vector<pos> hull;

    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull[hull.size() - 1], arr[i]) <= 0) {
            hull.pop_back();
        }

        hull.push_back(arr[i]);
    }

    cout << hull.size();
}