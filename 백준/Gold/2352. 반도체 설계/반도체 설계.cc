#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> port(n);
    for (int i=0; i<n; i++)
        cin >> port[i];

    int len = 0;
    vector<int> lis(n+1, INF);
    lis[0] = -INF;

    for (int i=0; i<n; i++) {
        auto iter = lower_bound(lis.begin(), lis.begin() + (i + 1), port[i]);
        int j = (int)(iter - lis.begin());
        lis[j] = port[i];
        len = max(len, j);
    }

    cout << len;
}