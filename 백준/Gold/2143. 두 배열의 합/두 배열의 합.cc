#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m;
int a[1010], b[1010];
vector<int> sum_a, sum_b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    //
    //
    //

    for (int i = 0; i < n; i++) {
        int sum = 0;
        
        for (int j = i; j < n; j++) {
            sum += a[j];
            
            sum_a.push_back(sum);
        }
    }

    for (int i = 0; i < m; i++) {
        int sum = 0;

        for (int j = i; j < m; j++) {
            sum += b[j];
            
            sum_b.push_back(sum);
        }
    }

    //
    //
    //

    sort(sum_b.begin(), sum_b.end());

    long long ans = 0;

    for (int num : sum_a) {
        auto lo = lower_bound(sum_b.begin(), sum_b.end(), t - num);
        auto up = upper_bound(sum_b.begin(), sum_b.end(), t - num);

        ans += (up - lo);
    }

    cout << ans;
}