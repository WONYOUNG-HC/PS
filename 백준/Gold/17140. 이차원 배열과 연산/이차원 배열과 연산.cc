#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int r, c, k;
int arr[110][110];
int mr = 3, mc = 3;

void rsort(int y) {
    map<int, int> m;
    for (int i = 1; i <= 100; i++) {
        if (arr[y][i] == 0)
            continue;

        m[arr[y][i]]++;
    }

    vector<pii> v;
    for (auto it : m) 
        v.emplace_back(it.second, it.first);

    sort(v.begin(), v.end());
    int idx = 1;
    for (auto pr : v) {
        if (idx > 100)
            break;
        arr[y][idx++] = pr.second;

        if (idx > 100)
            break;
        arr[y][idx++] = pr.first;
    }

    for (int i = idx; i <= 100; i++)
        arr[y][i] = 0;
}

void csort(int x) {
    map<int, int> m;
    for (int i = 1; i <= 100; i++) {
        if (arr[i][x] == 0)
            continue;

        m[arr[i][x]]++;
    }

    vector<pii> v;
    for (auto it : m) 
        v.emplace_back(it.second, it.first);

    sort(v.begin(), v.end());
    int idx = 1;
    for (auto pr : v) {
        if (idx > 100)
            break;
        arr[idx++][x] = pr.second;

        if (idx > 100)
            break;
        arr[idx++][x] = pr.first;
    }

    for (int i = idx; i <= 100; i++)
        arr[idx++][x] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> k;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            cin >> arr[i][j];

    int ans = 0;
    while (ans <= 100) {
        if (arr[r][c] == k) {
            cout << ans;
            return 0;
        }

        if (mr >= mc) {
            for (int i = 1; i <= mr; i++)
                rsort(i);
        }
        else {
            for (int i = 1; i <= mc; i++)
                csort(i);
        }

        mr = 0, mc = 0;
        for (int i = 1; i <= 100; i++)
            for (int j = 1; j <= 100; j++)
                if (arr[i][j] > 0)
                    mr = max(mr, i), mc = max(mc, j);

        ans++;
    }

    cout << -1;
}