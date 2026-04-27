#include <iostream>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, k;
pii arr[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        
        arr[i].second = i;
    }

    sort(arr, arr + n);

    int ans = 0;

    do {
        int cur = 500;

        for (int i = 0; i < n; i++) {
            cur += arr[i].first;
            cur -= k;

            if (cur < 500) {
                ans -= 1;
                
                break;
            }
        }

        ans += 1;

    } while (next_permutation(arr, arr + n));

    cout << ans;
}