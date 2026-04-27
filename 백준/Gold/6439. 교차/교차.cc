#include <iostream>
#include <cmath>

#define x first
#define y second

using namespace std;
using pos = pair<int, int>;

int ccw(pos p1, pos p2, pos p3) {
    int ret = ((p1.x - p3.x) * (p2.y - p3.y)) - ((p1.y - p3.y) * (p2.x - p3.x));

    if (ret == 0) {
        return 0;
    }

    return ret / abs(ret);
}

pos sq1, sq2;
pos l1, l2;

bool is_inter(pos p1, pos p2, pos p3, pos p4) {
    int ccw1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int ccw2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (ccw1 == 0 && ccw2 == 0) {
        if (p2 < p1) {
            swap(p2, p1);
        }

        if (p4 < p3) {
            swap(p4, p3);
        }

        return (p2 >= p3 && p4 >= p1);
    }

    return ccw1 <= 0 && ccw2 <= 0;
}

bool is_inside(pos s1, pos s2, pos p) {
    return s1.x <= p.x && p.x <= s2.x && s1.y <= p.y && p.y <= s2.y;
}

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        cin >> l1.x >> l1.y >> l2.x >> l2.y >> sq1.x >> sq1.y >> sq2.x >> sq2.y;

        if (sq2 < sq1) {
            swap(sq2, sq1);
        }

        if (sq1.y > sq2.y) {
            swap(sq1.y, sq2.y);
        }

        pos s1, s2, s3, s4;

        s1 = sq1;
        
        s2.x = sq1.x;
        s2.y = sq2.y;

        s3.x = sq2.x;
        s3.y = sq1.y;

        s4 = sq2;

        bool ans1 = is_inter(s1, s2, l1, l2) || is_inter(s2, s3, l1, l2) || is_inter(s3, s4, l1, l2) || is_inter(s4, s1, l1, l2);

        if (ans1) {
            cout << "T\n"; 

            continue;
        }

        if (is_inside(s1, s4, l1) && is_inside(s1, s4, l2)) {
            cout << "T\n";
        } else {
            cout << "F\n";
        }
    }
}