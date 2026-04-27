#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v, nums;
set<vector<int>> s;

void Permutation(int cnt) {
    if (cnt == m) {
        s.insert(v);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (v.empty() || v.back() <= nums[i]) {
            v.push_back(nums[i]);
            Permutation(cnt + 1);
            v.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    nums.resize(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());
    Permutation(0);

    for (auto& vec : s) {
        for (int i : vec)
            cout << i << ' ';
        cout << '\n';
    }
}