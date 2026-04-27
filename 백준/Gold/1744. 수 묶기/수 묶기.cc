#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    priority_queue<int> pos;
    priority_queue<int, vector<int>, greater<>> neg;
    int zer = 0, one = 0;

    for (int i = 0; i < n; i++) {
        int c; cin >> c;

        if (c == 0)
            zer++;
        else if (c == 1)
            one++;
        else if (c > 0)
            pos.push(c);
        else
            neg.push(c);
    }

    int ans = 0;
    while (!pos.empty()) {
        int a = 1;
        if (pos.size() > 1) {
            a = pos.top();
            pos.pop();
        }

        ans += a * pos.top();
        pos.pop();
    }

    while (!neg.empty()) {
        int a = 1;
        if (neg.size() > 1) {
            a = neg.top();
            neg.pop();
        }
        else if (zer) {
            a = 0;
            zer--;
        }

        ans += a * neg.top();
        neg.pop();
    }

    cout << ans + one;
}