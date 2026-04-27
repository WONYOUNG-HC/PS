#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;
int t[20], p[20];

void recur(int day, int start, bool state, int cur) {
    if (start != -1 && start + t[start] <= day) {
        state = true;
    }

    if (day == n) {
        if (state)
            ans = max(ans, cur);
        return;
    }

    if (state) {
        recur(day + 1, day, false, cur + p[day]);
        recur(day + 1, -1, true, cur);
    }
    else {
        recur(day + 1, start, false, cur);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i] >> p[i];

    recur(1, 0, false, p[0]);
    recur(1, -1, true, 0);

    cout << ans;
}