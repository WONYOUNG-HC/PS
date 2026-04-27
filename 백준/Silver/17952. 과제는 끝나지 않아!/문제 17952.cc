#include <iostream>
#include <stack>

#define TIME first
#define SCORE second

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    stack<pair<int, int>> s;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int order; cin >> order;

        if (order == 1) {
            int score, time;
            cin >> score >> time;
            s.emplace(time, score);
        }

        if (s.empty())
            continue;

        s.top().TIME -= 1;

        if (s.top().TIME == 0) {
            ans += s.top().SCORE;
            s.pop();
        }
    }

    cout << ans;
}