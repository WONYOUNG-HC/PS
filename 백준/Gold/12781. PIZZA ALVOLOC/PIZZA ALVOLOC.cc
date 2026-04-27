#include <iostream>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>
#define X first
#define Y second

using namespace std;

pll p1, p2, p3, p4;

int ccw(pll a, pll b, pll c) {
    ll ret = ((b.X - a.X) * (c.Y - a.Y)) - ((b.Y - a.Y) * (c.X - a.X));

    if (ret > 0) return 1;
    if (ret < 0) return -1;
    return 0;
}

int main() {
    cin >> p1.X >> p1.Y >> p2.X >> p2.Y >> p3.X >> p3.Y >> p4.X >> p4.Y;

    int o1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int o2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
    
    cout << (o1 < 0 && o2 < 0);
}