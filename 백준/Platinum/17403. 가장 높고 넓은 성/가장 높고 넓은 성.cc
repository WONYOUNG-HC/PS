#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pos {
    int id, x, y;

    pos(int _id, int _x, int _y) {
        id = _id;
        x = _x;
        y = _y;
    }

    bool operator<(pos arg) const {
        if (y == arg.y) {
            return x < arg.x;
        }

        return y < arg.y;
    }
};

int n;
vector<pos> v;
int height[1010];
int k;

int ccw(pos a, pos b, pos c) {
    return ((a.x - c.x) * (b.y - c.y)) - ((a.y - c.y) * (b.x - c.x));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0;  i < n; i++) {
        int x, y;

        cin >> x >> y;

        v.emplace_back(i, x, y);
    }

    while (v.size() > 2) {
        auto min_pos_it = min_element(v.begin(), v.end());

        swap(*min_pos_it, *v.begin());

        sort(v.begin() + 1, v.end(), [](pos a, pos b) -> bool {
            int cc = ccw(v[0], a, b);

            if (cc != 0) {
                return cc > 0;
            }

            return a < b;
        });

        //
        //
        //
        
        vector<pos> hull = {v[0], v[1]};

        for (int i = 2; i < v.size(); i++) {
            while (hull.size() >= 2 && ccw(*(hull.rbegin() + 1), *hull.rbegin(), v[i]) <= 0) {
                hull.pop_back();
            }

            hull.push_back(v[i]);
        }

        if (hull.size() < 3) {
            break;
        }

        //
        //
        //

        vector<pos> _v;

        k += 1;

        for (auto p : hull) {
            height[p.id] = k;
        }

        for (pos p : v) {
            if (height[p.id] == 0) {
                _v.push_back(p);
            }
        }

        v.swap(_v);
    }

    for (int i = 0; i < n; i++) {
        cout << height[i] << ' ';
    }
}