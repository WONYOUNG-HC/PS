#include <iostream>

using namespace std;

int n, k;
int arr[1010];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    int ans = 1010;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        int start = arr[i] - (i * k);

        if (start < 1)
            continue;

        for (int j = 0; j < n; j++) {
            if (arr[j] != start + (j * k)) {
                cnt++;
            }
        }

        ans = min(ans, cnt);
    }

    cout << ans;
}