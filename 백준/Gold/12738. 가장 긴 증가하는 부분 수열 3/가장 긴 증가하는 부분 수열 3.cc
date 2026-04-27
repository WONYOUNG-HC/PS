#include <iostream>
#include <stack>
#include <algorithm>

#define INF (1e9 + 10)
#define N 1'000'010

using namespace std;

int n, nums[N], lis[N], pos[N];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &nums[i]);

    lis[0] = -INF;
    fill(lis + 1, lis + N, INF);

    int last = 0;
    for (int i = 1; i <= n; i++) {
        int j = lower_bound(lis, lis + (i + 1), nums[i]) - lis;

        pos[i] = j;
        lis[j] = nums[i];
        if (j > pos[last]) last = i;
    }

    cout << pos[last] << '\n';
    /*
    stack<int> s;
    s.push(last--);

    while (pos[s.top()] != 1) {
        if (pos[last] + 1 == pos[s.top()])
            s.push(last);
        last--;
    }

    while (!s.empty()) {
        cout << nums[s.top()] << ' ';
        s.pop();
    }
    */
}