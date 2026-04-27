#include <iostream>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int n;
vector<pair<long long, long long>> hull;

int ccw(const pair<long long, long long>& p1, const pair<long long, long long>& p2, const pair<long long, long long>& p3) {
    long long ret = p1.X * p2.Y - p1.Y * p2.X + p2.X * p3.Y - p3.X * p2.Y + p3.X * p1.Y - p1.X * p3.Y;

    if (ret > 0) return 1;
    else if (ret < 0) return -1;
    return 0;
}

void SetP0() {
    int idx = 0;

    for (int i = 1; i < hull.size(); i++) {
        if (hull[i].X < hull[idx].X || (hull[i].X == hull[idx].X && hull[i].Y < hull[idx].Y))
            idx = i;
    }

    swap(hull[0], hull[idx]);
}

bool Pred(const pair<long long, long long>& left, const pair<long long, long long>& right) {
    int ret = ccw(hull[0], left, right);

    if (ret != 0)
        return ret > 0;

    if (left.Y == right.Y)
        return left.X < right.X;

    return left.Y > right.Y;
}

void GrahamScan() {
    vector<pair<long long, long long>> s = {hull[0], hull[1], hull[2]};

    for (int i = 3; i < hull.size(); i++) {
        while (s.size() >= 2 && ccw(hull[i], *(s.end() - 2), s.back()) < 0)
            s.pop_back();

        s.push_back(hull[i]);
    }

    cout << s.size() << '\n';

    for (auto& pr : s)
        cout << pr.X << ' ' << pr.Y << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        long long x, y; char c;
        cin >> x >> y >> c;

        if (c == 'Y')
            hull.emplace_back(x, y);
    }

    SetP0();

    sort(hull.begin() + 1, hull.end(), Pred);

    cout << hull.size() << '\n';
    for (auto& pr : hull)
        cout << pr.X << ' ' << pr.Y << '\n';
    
    //GrahamScan();
}