#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct pos {
    double x, y;

    pos(double _x, double _y) {
        x = _x;
        y = _y;
    }

    bool operator<=(pos arg) {
        if (x == arg.x) {
            return y <= arg.y;
        }

        return x <= arg.x;
    }
};

double ccw(pos p1, pos p2, pos p3) {
    double w = ((p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x));

    if (w == 0) {
        return 0;
    }

    return w / abs(w);
}

void sort_pos(pos &p1, pos &p2) {
    if (p2 <= p1) {
        swap(p1, p2);
    }
}

double det(double a11, double a12, double a21, double a22) {
    return a11 * a22 - a12 * a21;
}

void prt_inter(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    double det_a = det(x2 - x1, -(x4 - x3), y2 - y1, -(y4 - y3));
    double det_s = det(x3 - x1, -(x4 - x3), y3 - y1, -(y4 - y3));

    if (det_a == 0 && (x2 == x3 && y2 == y3)) {
        cout << x2 << ' ' << y2;
    } else if (det_a == 0 && (x1 == x4 && y1 == y4)) {
        cout << x1 << ' ' << y1;
    } else if (det_a != 0) {
        double s = det_s / det_a;

        double x = x1 + s * (x2 - x1);
        double y = y1 + s * (y2 - y1);

        cout << x << ' ' << y;
    }
}

int main() {
    double x1, y1, x2, y2;
    double x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    pos p1 = {x1, y1};
    pos p2 = {x2, y2};
    pos p3 = {x3, y3};
    pos p4 = {x4, y4};

    double w1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    double w2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    cout << fixed;
    cout.precision(9);

    if (w1 == 0 && w2 == 0) {
        sort_pos(p1, p2);
        sort_pos(p3, p4);

        if (p1 <= p4 && p3 <= p2) {
            cout << 1 << '\n';

            prt_inter(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, p4.x, p4.y);
        } else {
            cout << 0 << '\n';
        }

        return 0;
    }

    if (w1 <= 0 && w2 <= 0) {
        cout << 1 << '\n';

        prt_inter(x1, y1, x2, y2, x3, y3, x4, y4);
    } else {
        cout << 0;
    }
}