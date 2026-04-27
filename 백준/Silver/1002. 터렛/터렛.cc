#include <iostream>
#include <cmath>

#define pdd pair<double, double>
#define X first
#define Y second

using namespace std;

pdd p1, p2;
double r1, r2;

int solve() {
    cin >> p1.X >> p1.Y >> r1 >> p2.X >> p2.Y >> r2;

    if (p1 == p2 && r1 == r2)
        return -1;

    double dist = sqrt(pow(p1.X - p2.X, 2) + pow(p1.Y - p2.Y, 2));

    if (dist > r1 + r2)
        return 0;

    if (dist == r1 + r2)
        return 1;

    if (max(r1, r2) > dist + min(r1, r2))
        return 0;

    if (max(r1, r2) == dist + min(r1, r2)) {
        return 1;
    }

    return 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--)
        cout << solve() << '\n';
}