#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> nums;

void Permutation(vector<int>& v) {
    if (v.size() == m) {
        for (int i : v)
            cout << i << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        v.push_back(nums[i]);
        Permutation(v);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;

    nums.resize(n);
    for (int i = 0; i < n; i++)
        nums[i] = i + 1;

    vector<int> v;
    Permutation(v);
}