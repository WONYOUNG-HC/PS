#include <iostream>
#include <algorithm>

#define INF (1e9 + 10)
#define N 1'000'010

using namespace std;

int n, a[N], b[N], arr[N], lis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        b[num] = i;
    }

    for (int i = 0; i < n; i++)
        arr[i] = b[a[i]];

    lis[0] = -INF;
    fill(lis + 1, lis + N, INF);

    int len = 1;
    for (int i = 0; i < n; i++) {
        int j = lower_bound(lis, lis + (i + 2), arr[i]) - lis;

        lis[j] = arr[i];
        if (j > len) len = j;
    }

    cout << len;
}