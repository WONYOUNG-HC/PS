#include <iostream>
#include <vector>

using namespace std;

void BackTracking(vector<int>& v, int cnt, int prev, int n, int m);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i=0; i<n; i++)
        v[i] = i+1;

    BackTracking(v, 0, 0, n, m);
}

vector<int> ans;

void BackTracking(vector<int>& v, int cnt, int prev, int n, int m) {
    if (cnt == m) {
        for (int i : ans)
            cout << i << ' ';
        cout << '\n';
        return;
    }

    for (int i=0; i<n; i++) {
        if (prev <= v[i]) {
            ans.push_back(v[i]);
            BackTracking(v, cnt+1, v[i], n, m);
            ans.pop_back();
        }
    }
}