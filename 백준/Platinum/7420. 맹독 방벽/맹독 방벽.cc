#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct pos {
    double x, y;
    bool operator< (pos &p) {
        return this->y == p.y ? this->x < p.x : this->y < p.y;
    }
};

int n, l;
pos arr[1010];

double ccw(pos &a, pos &b, pos &c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double dist(pos &a, pos &b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double inner(pos &a, pos &b) {
    return a.x * b.x + a.y * b.y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l;
    for (int i = 0; i < n; i++)
        cin >> arr[i].x >> arr[i].y;

    for (int i = 1; i < n; i++)
        if (arr[i] < arr[0]) swap(arr[0], arr[i]);

    sort(arr + 1, arr + n, [&](pos &left, pos &right) {
        double c = ccw(arr[0], left, right);
        return c == 0 ? left < right : c > 0;
    });
    
    vector<pos> st{arr[0], arr[1]};
    for (int i = 2; i < n; i++) {
        while (st.size() > 1 && ccw(st[st.size() - 2], st[st.size() - 1], arr[i]) <= 0)
            st.pop_back();
        st.push_back(arr[i]);
    }

    double ans = 0;
    for (auto it = st.begin(); it < st.end(); it++) {
        // pos prev = (it == st.begin() ? *--st.end() : *(it - 1));
        pos cur = *it;
        pos next = (it == --st.end() ? *st.begin() : *(it + 1));

        // pos v1 = {prev.x - cur.x, prev.y - cur.y};
        // pos v2 = {next.x - cur.x, next.y - cur.y};
        
        // ans += dist(cur, prev);
        // ans += acos(inner(v1, v2) / dist(cur, prev) / dist(cur, next)) * l;
        
        ans += dist(cur, next);
    }
    ans += 2 * M_PI * l;

    cout << round(ans);
}