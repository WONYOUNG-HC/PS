#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
set<vector<int>> s;
vector<int> nums;

void Permutation(vector<int>& v, vector<bool>& visit, int cnt);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    nums.resize(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> v;
    vector<bool> visit(m);
    Permutation(v,visit, 0);

    for (const auto& iter : s) {
        for (int i = 0; i < m; i++)
            cout << iter[i] << ' ';
        cout << '\n';
    }
}

void Permutation(vector<int>& v, vector<bool>& visit, int cnt) {
    if (cnt == m) {
        s.insert(v);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visit[i])
            continue;

        v.push_back(nums[i]);
        visit[i] = true;
        Permutation(v, visit, cnt + 1);
        v.pop_back();
        visit[i] = false;
    }
}