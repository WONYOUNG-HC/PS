#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
vector<int> seq;
set<vector<int>> ans;

void dfs(int cur, int cnt) {
    if (cnt == m) {
        ans.insert(seq);
        return;
    }

    for (int i = cur; i < n; i++) {
        seq.push_back(arr[i]);
        dfs(i + 1, cnt + 1);
        seq.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    dfs(0, 0);

    for (auto& v : ans) {
        for (int x : v)
            cout << x << ' ';
        cout << '\n';
    }
}