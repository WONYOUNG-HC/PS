#include <iostream>

using namespace std;

int n;
int arr[10];
int ans[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        int cnt = 0;

        for (int j = 0; j < n; j++) {
            if (ans[j] > 0) {
                continue;
            }

            if (cnt == arr[i - 1]) {
                ans[j] = i;
            
                break;
            }

            cnt += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}