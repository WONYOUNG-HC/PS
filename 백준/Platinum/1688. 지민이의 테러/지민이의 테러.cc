#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct pos {
    double x, y;
};

int n;
pos arr[10010];

double ccw(pos p1, pos p2, pos p3) {
    double w = ((p2.x - p1.x) * (p3.y - p1.y)) - ((p3.x - p1.x) * (p2.y - p1.y));

    if (w == 0) {
        return w;
    }

    return w / abs(w);
}

bool in_border(pos p0, pos p1, pos p2) {
    if (ccw(p0, p1, p2) == 0) {
        return min(p1.x, p2.x) <= p0.x && p0.x <= max(p1.x, p2.x) && min(p1.y, p2.y) <= p0.y && p0.y <= max(p1.y, p2.y);
    }

    return false;
}

bool cross(pos p0, pos p1, pos p2) {
    pos p4 = {1e9 + 7, p0.y};

    if (p1.y == p0.y) {
        p1.y += 1e-9;
    }

    if (p2.y == p0.y) {
        p2.y += 1e-9;
    }

    double w1 = ccw(p1, p2, p0) * ccw(p1, p2, p4);
    double w2 = ccw(p0, p4, p1) * ccw(p0, p4, p2);

    return w1 < 0 && w2 < 0;
}

bool protect(double x, double y) {
    pos p0 = {x, y};
    int corss_cnt = 0;

    for (int i = 0; i < n; i++) {
        pos p1 = arr[i];
        pos p2 = arr[(i + 1) % n];

        if (in_border(p0, p1, p2)) {
            return true;
        }

        corss_cnt += cross(p0, p1, p2);
    }

    return corss_cnt % 2 == 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    for (int i = 0; i < 3; i++) {
        double x, y;

        cin >> x >> y;

        if (protect(x, y)) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}