#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void BackTracking(vector<int>& v, int cnt, int n, int m);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i=0; i<n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    BackTracking(v, 0, n, m);
}

vector<int> ans;

bool Promising(int i) {
    for (int j : ans) {
        if (i == j)
            return false;
    }

    return true;
}

void BackTracking(vector<int>& v, int cnt, int n, int m) {
    if (cnt == m) {
        for (int i : ans)
            cout << i << ' ';
        cout << '\n';
        return;
    }

    for (int i=0; i<n; i++) {
        if (Promising(v[i])) {
            ans.push_back(v[i]);
            BackTracking(v, cnt+1, n, m);
            ans.pop_back();
        }
    }
}