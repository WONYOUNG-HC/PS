#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using pii = pair<int, int>;

int n, l;
pii arr[10010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l;
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n);

    int ans = 0, cover = -1;
    for (int i = 0; i < n; i++) {
        int start = max(arr[i].first, cover);
        int end = arr[i].second;
        
        cover = start + (end - start) / l * l;
        ans += (end - start) / l;
        if (cover < end) {
            cover += l;
            ans++;
        }
    }

    cout << ans;
}