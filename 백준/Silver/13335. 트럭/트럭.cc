#include <iostream>
#include <deque>

using namespace std;

int n, w, l;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w >> l;

    deque<int> dq(w), q(n);
    for (int& x : q) cin >> x;

    int ans = 0, sum = 0;
    while (!q.empty() || sum != 0) {
        sum -= dq.front();
        dq.pop_front();

        int car = 0;
        if (!q.empty() && q.front() + sum <= l) {
            car = q.front();
            q.pop_front();
        }

        sum += car;
        dq.push_back(car);
        ans++;
    }

    cout << ans;
}