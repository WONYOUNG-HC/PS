#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for (int i=0; i<n; i++)
        cin >> nums[i];

    int i=0, j=-1;
    int sum = nums[i], cnt = 0;
    while (i != n || sum > m) {
        if (sum < m) sum += nums[++i];
        else if (sum > m) sum -= nums[++j];
        else {
            cnt++;
            sum += nums[++i];
        }
    }

    cout << cnt;
}