#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> nums;

void DivideCandy(int n, int m);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    nums.resize(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    DivideCandy(n, m);
}

bool Decision(int n, int m, int mid) {
    int sum = 0, group = 1;
    for (int i = 0; i < n; i++) {
        if (sum + nums[i] > mid) {
            group++;
            sum = 0;
        }

        sum += nums[i];

        if (group > m)
            return false;
    }

    return group <= m;
}

void DivideCandy(int n, int m) {
    int left = *max_element(nums.begin(), nums.end());
    int right = accumulate(nums.begin(), nums.end(), 0);

    while (left <= right) {
        int mid = (left + right) / 2;

        if (Decision(n, m, mid))
            right = mid - 1;
        else
            left = mid + 1;
    }

    cout << left << '\n';

    int sum = 0, cnt = 0, group = 1;
    for (int i = 0; i < n; i++) {
        if (sum + nums[i] > left) {
            cout << cnt << ' ';

            group++;
            sum = 0;
            cnt = 0;
        }

        sum += nums[i];
        cnt++;

        if ((group - 1) + (n - i) == m) {
            cout << cnt << ' ';
            for (int j = i + 1; j < n; j++)
                cout << 1 << ' ';

            return;
        }
    }

    cout << cnt;
}