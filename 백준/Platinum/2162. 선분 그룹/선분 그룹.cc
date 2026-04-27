#include <iostream>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>
#define X first
#define Y second

using namespace std;

int n;
pair<pll, pll> arr[3010];
int root[3010], level[3010], cnt[3010];

int ccw(pll a, pll b, pll c) {
    ll ret = ((b.X - a.X) * (c.Y - a.Y)) - ((b.Y - a.Y) * (c.X - a.X));

    if (ret > 0) return 1;
    if (ret < 0) return -1;
    return 0;
}

bool isInter(pll p1, pll p2, pll p3, pll p4) {
    int o1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int o2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (o1 == 0 && o2 == 0) {
        if (p1 > p2) swap(p1, p2);
        if (p3 > p4) swap(p3, p4);

        return p3 <= p2 && p1 <= p4;
    }

    return o1 <= 0 && o2 <= 0;
}

int find(int x) {
    if (x == root[x])
        return x;
    return root[x] = find(root[x]);
}

void merge(int x, int y) {
    if (level[x] < level[y])
        swap(x, y);

    root[y] = x;
    cnt[x] += cnt[y];

    if (level[x] == level[y])
        level[x]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].first.X >> arr[i].first.Y >> arr[i].second.X >> arr[i].second.Y;

    for (int i = 0; i < n; i++)
        root[i] = i, level[i] = 1, cnt[i] = 1;

    int group = n;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = find(i), y = find(j);
            if (x != y && isInter(arr[i].first, arr[i].second, arr[j].first, arr[j].second)) {
                merge(x, y);
                group--;
            }
        }
    }

    cout << group << '\n' << *max_element(cnt, cnt + n);
}