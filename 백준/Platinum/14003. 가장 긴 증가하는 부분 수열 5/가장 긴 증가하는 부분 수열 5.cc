#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2e9

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int last = 0;
    vector<int> lis(n+1, INF);
    vector<int> pos(n);
    lis[0] = -INF;

    for (int i=0; i<n; i++) {
        auto iter = lower_bound(lis.begin(), lis.begin() + (i+1), nums[i]);
        int j = (int)(iter - lis.begin());
        pos[i] = j;
        lis[j] = nums[i];
        if (j >= pos[last]) last = i;
    }

    cout << pos[last] << '\n';

    vector<int> sequence;
    int len = pos[last] - 1;
    int idx = last - 1;

    sequence.push_back(nums[last]);
    while (len != 0) {
        if (pos[idx] == len) {
            sequence.push_back(nums[idx]);
            len--;
        }
        idx--;
    }

    for (auto riter = sequence.rbegin(); riter != sequence.rend(); riter++)
        cout << *riter << ' ';
}