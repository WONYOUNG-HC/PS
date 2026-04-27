#include <iostream>
#include <queue>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

struct cmp {
    bool operator()(const pll &a, const pll &b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }

        return a.first > b.first;
    }
};

int n;
ll d;
priority_queue<pll, vector<pll>, cmp> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        ll a, b;

        cin >> a >> b;

        pq.push({min(a, b), max(a, b)});
    }

    cin >> d;

    //
    //
    //

    int ans = 0;
    priority_queue<pll, vector<pll>, greater<pll>> contain;

    while (!pq.empty()) {
        if (pq.top().first + d < pq.top().second) {
            pq.pop();
            continue;
        }

        while (!contain.empty() && contain.top().first + d < pq.top().second) {
            contain.pop();
        }

        contain.push(pq.top());
        pq.pop();

        ans = max(ans, (int)contain.size());
    }

    cout << ans;
}