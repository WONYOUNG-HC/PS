#include <iostream>
#include <algorithm>

using namespace std;

struct diff {
    int s, e;
};

int n, k;
int arr[100010];
diff df[100010];
bool cut[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (i < n - 1)
            df[i] = {i, i + 1};
    }

    sort(arr, arr + n);
    sort(df, df + n - 1, [](const diff &left, const diff &right) -> bool {
        return (arr[left.e] - arr[left.s]) > (arr[right.e] - arr[right.s]);
    });
    
    for (int i = 0; i < min(k, n) - 1; i++)
        cut[df[i].s] = true;
    
    int ans = 0;
    int s = 0, e = 0;
    while (e < n) {
        if (cut[e]) {
            ans += arr[e] - arr[s];
            s = ++e;
        }
        else {
            e++;
        }
    }
    ans += arr[e - 1] - arr[s];
    cout << ans;
}