#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Pos {
    long long y, x;
};

int CCW(const Pos& a, const Pos& b, const Pos& c) {
    long long sign = a.x * b.y - a.y * b.x + b.x * c.y - c.x * b.y + c.x * a.y - a.x * c.y;

    if (sign > 0) return 1;
    else if (sign < 0) return -1;
    else return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Pos a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    cout << CCW(a, b, c);
}