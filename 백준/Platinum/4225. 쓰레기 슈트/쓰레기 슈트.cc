#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct pos {
    double x, y;
};

int n;
pos arr[110];

double ccw(pos a, pos b, pos c) {
    return ((b.x - a.x) * (c.y - a.y)) - ((b.y - a.y) * (c.x - a.x));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed;
    cout.precision(2);

    for (int tc = 1; ; tc++) {
        cin >> n;

        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            cin >> arr[i].x >> arr[i].y;
        }

        //
        //
        //

        auto min_ptr = min_element(arr, arr + n, [](pos a, pos b) -> bool {
            if (a.x == b.x) {
                return a.y < b.y;
            }

            return a.x < b.x;
        });
        
        swap(arr[0], *min_ptr);

        //
        //
        //

        sort(arr + 1, arr + n, [](pos a, pos b) -> bool {
            double w = ccw(arr[0], a, b);

            if (w == 0) {
                if (a.x == b.x) {
                 return a.y < b.y;
                }

                return a.x < b.x;
            }

            return w > 0;
        });

        //
        //
        //

        vector<pos> hull = {arr[0], arr[1]};

        for (int i = 2; i < n; i++) {
            while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull[hull.size() - 1], arr[i]) <= 0) {
                hull.pop_back();
            }

            hull.push_back(arr[i]);
        }

        //
        //
        //

        double ans = 1e10;

        for (int i = 0; i < hull.size(); i++) {
            double max_len = 0;
            pos p1 = hull[i];
            pos p2 = hull[(i + 1) % hull.size()];

            for (int j = 0; j < hull.size(); j++) {
                pos p0 = hull[j];

                double dist = abs(((p2.x - p1.x) * (p0.y - p1.y)) - ((p0.x - p1.x) * (p2.y - p1.y)));
                dist /= hypot(p2.x - p1.x, p2.y - p1.y);

                max_len = max(max_len, dist);
            }

            ans = min(ans, max_len);
        }

        if ((ans * 100) - floor(ans * 100) > 1e-12) {
            ans += 0.01;
        }

        ans = floor(ans * 100) / 100;

        cout << "Case " << tc << ": " << ans << '\n';
    }
}