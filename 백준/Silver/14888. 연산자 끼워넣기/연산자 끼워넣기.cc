#include <iostream>
#include <algorithm>

using namespace std;

int n;
int mx = -1e9, mn = 1e9;
int nums[15];
int op[4];

void DFS(int cur, int cnt) {
    if (cnt == n) {
        mx = max(mx, cur);
        mn = min(mn, cur);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            op[i]--;

            if (i == 0)
                DFS(cur + nums[cnt], cnt + 1);
            else if (i == 1)
                DFS(cur - nums[cnt], cnt + 1);
            else if (i == 2)
                DFS(cur * nums[cnt], cnt + 1);
            else
                DFS(cur / nums[cnt], cnt + 1);

            op[i]++;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = 0; i < 4; i++)
        cin >> op[i];

    DFS(nums[0], 1);

    cout << mx << '\n' << mn;
}