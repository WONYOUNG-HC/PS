#include <iostream>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

struct Pos {
    long long y, x;

    explicit Pos() = default;
    explicit Pos(long long y, long long x) : y(y), x(x) {}

    bool operator==(const Pos& arg) const {
        return y == arg.y && x == arg.x;
    }
};

int n;
Pos p0;
Pos prison;

int ccw(const Pos& a, const Pos& b, const Pos& c) {
    long long sign = a.x * b.y - a.y * b.x + b.x * c.y - c.x * b.y + c.x * a.y - a.x * c.y;

    if (sign > 0) return 1;
    else if (sign < 0) return -1;
    else return 0;
}

bool Pred(const Pos &left, const Pos &right) {
    int sign = ccw(p0, left, right);

    if (sign != 0)
        return sign > 0;

    if (left.y != right.y)
        return left.y < right.y;
    return left.x < right.x;
}

void SetMin(list<Pos>& lt) {
    auto min_iter = lt.begin();

    for (auto iter = ++lt.begin(); iter != lt.end(); iter++) {
        const Pos& cur = *iter;
        const Pos& min_value = *min_iter;

        if (cur.y < min_value.y || (cur.y == min_value.y && cur.x < min_value.x)) {
            min_iter = iter;
        }
    }

    p0 = *min_iter;
    iter_swap(lt.begin(), min_iter);
}

bool GrahamScan(list<Pos>& lt) {
    stack<Pos> s;
    s.push(p0); s.push(*(++lt.begin()));

    bool prison_linear = false;

    for (auto iter = next(lt.begin(), 2); iter != lt.end(); iter++) {
        while (s.size() >= 2) {
            Pos t2 = s.top(); s.pop();
            Pos t1 = s.top();

            int sign = ccw(t1, t2, *iter);

            if (sign > 0) {
                s.push(t2);
                break;
            }
            else if (sign < 0 && prison_linear) {
                prison_linear = false;
            }
            else if (sign == 0 && t2 == prison) {
                prison_linear = true;
            }
        }

        s.push(*iter);
    }

    if (prison_linear)
        return false;

    while (!s.empty()) {
        if (s.top() == prison)
            return false;

        lt.remove(s.top());
        s.pop();
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> prison.x >> prison.y;

    list<Pos> lt;
    lt.push_back(prison);

    for (int i = 1; i < n + 1; i++) {
        int x, y;
        cin >> x >> y;

        lt.emplace_back(y, x);
    }

    int ans = 0;
    while (lt.size() > 3) {
        SetMin(lt);

        lt.sort(Pred);

        if (GrahamScan(lt))
            ans++;
        else
            break;
    }

    cout << ans;
}