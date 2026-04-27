#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct pos {
    ll x, y;
};

int n;
pos arr[100010];

long long ccw(pos a, pos b, pos c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

long long ccw(pos a, pos b, pos c, pos d) {
    pos u = {b.x - a.x, b.y - a.y};
    pos v = {d.x - c.x, d.y - c.y};

    return u.x * v.y - u.y * v.x;
}

long long dist(pos a, pos b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    auto min_pos = min_element(arr, arr + n, [](pos a, pos b) {
        if (a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    });

    swap(*arr, *min_pos);

    sort(arr + 1, arr + n, [](pos a, pos b) {
        ll w = ccw(arr[0], a, b);

        if (w == 0) {
            if (a.y == b.y) {
                return a.x < b.x;
            }

            return a.y < b.y;
        }

        return w > 0;
    });

    //
    //
    //

    vector<pos> hull = {arr[0], arr[1]};

    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2 && ccw(hull[hull.size()-2], hull[hull.size()-1], arr[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(arr[i]);
    }

    //
    //
    //

    int sz = hull.size();

    if (sz == 2) { 
        cout << dist(hull[0], hull[1]);

        return 0; 
    }

    ll ans = 0;
    int j = 1;

    for (int i = 0; i < sz; i++) {
        while (ccw(hull[i], hull[(i + 1) % sz], hull[j], hull[(j + 1) % sz]) > 0) {
            ans = max(ans, dist(hull[i], hull[j]));
            j = (j + 1) % sz;
        }

        ans = max(ans, dist(hull[i], hull[j]));

        if (ccw(hull[i], hull[(i + 1) % sz], hull[j], hull[(j + 1) % sz]) == 0) {
            ans = max(ans, dist(hull[(i + 1) % sz], hull[j]));
            ans = max(ans, dist(hull[i], hull[(j + 1) % sz]));
        }
    }

    cout << ans;
}