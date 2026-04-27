#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

vector<pair<int, int>> line;

void DeleteLine(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    line.resize(n);
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        line[i] = {a, b};
    }

    DeleteLine(n);
}

void DeleteLine(int n) {

    sort(line.begin(), line.end());

    int last = 0;
    vector<int> lis(n+1, INF);
    vector<int> pos(n);
    lis[0] = -INF;

    for (int i=0; i<n; i++) {
        auto iter = lower_bound(lis.begin(), lis.begin() + (i + 1), line[i].second);
        int j = (int)(iter - lis.begin());
        pos[i] = j;
        lis[j] = line[i].second;
        if (j >= pos[last]) last = i;
    }

    cout << n - pos[last] << '\n';

    vector<int> remove;
    int len = pos[last];
    int idx = n-1;

    while (idx >= 0) {
        if (pos[idx] == len)
            len--;
        else
            remove.push_back(line[idx].first);

        idx--;
    }

    for (auto iter = remove.rbegin(); iter != remove.rend(); iter++)
        cout << *iter << '\n';
}