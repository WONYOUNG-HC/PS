#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct pos {
    ll y, x;
};

int n;
pos arr[200010];
vector<pos> hull;

ll dist(pos a, pos b) {
    return ((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y));
}

ll ccw(pos a, pos b, pos c) {
    return ((a.x - c.x) * (b.y - c.y)) - ((a.y - c.y) * (b.x - c.x));
}

ll ccw(pos a, pos b, pos c, pos d) {
    pos u, v;

    u.x = b.x - a.x;
    u.y = b.y - a.y;

    v.x = d.x - c.x;
    v.y = d.y - c.y;

    return ccw({0, 0}, u, v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    while (tc--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> arr[i].x >> arr[i].y; 
        }

        //
        //
        //

        for (int i = 0; i < n; i++) {
            if (arr[i].y < arr[0].y || (arr[i].y == arr[0].y && arr[i].x < arr[0].x)) {
                swap(arr[i], arr[0]);
            }
        }

        sort(arr + 1, arr + n, [](pos a, pos b) -> bool {
            ll cw = ccw(arr[0], a, b);

            if (cw == 0) {
                return a.y < b.y || a.x < b.x;
            }

            return cw > 0;
        });

        //
        //
        //

        hull.clear();

        for (int i = 0; i < n; i++) {
            while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull[hull.size() - 1], arr[i]) <= 0) {
                hull.pop_back();
            }

            hull.push_back(arr[i]);
        }

        //
        //
        //

        ll len = 0;
        pos p1, p2;
        int j = 0;

        for (int i = 0; i < hull.size(); i++) {
            while (j + 1 < hull.size() && ccw(hull[i], hull[(i + 1) % hull.size()], hull[j], hull[j + 1]) >= 0) {
                ll d = dist(hull[i], hull[j]);

                if (d > len) {
                    p1 = hull[i];
                    p2 = hull[j];
                    len = d;
                }
                
                j += 1;
            }

            ll d = dist(hull[i], hull[j]);

            if (d > len) {
                p1 = hull[i];
                p2 = hull[j];
                len = d;
            }
        }

        cout << p1.x << ' ' << p1.y << ' ' << p2.x << ' ' << p2.y << endl;
    }
}