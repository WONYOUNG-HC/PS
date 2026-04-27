#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Work(int n, vector<pair<int, int>>& v);

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i=0; i<n; i++) {
        int d, w;
        cin >> d >> w;
        v[i] = {w, d};
    }

    cout << Work(n, v);
}

int Work(int n, vector<pair<int, int>>& v) {
    sort(v.begin(), v.end(), greater<>());
    vector<bool> day(1001, false);

    int ans = 0;
    for (int i=0; i<n; i++) {
        int w = v[i].first;
        int d = v[i].second;

        while (d > 0 && day[d])
            d--;

        if (d != 0) {
            day[d] = true;
            ans += w;
        }
    }

    return ans;
}