#include <iostream>
#include <algorithm>

using namespace std;

int x, n;
int arr[1000010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        cin >> x >> n;

        if (cin.eof()) {
            break;
        }

        x *= 10000000;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        int answer[2] = {-1, -1};

        for (int i = 0; i < n; i++) {
            int l1 = arr[i];

            int j = lower_bound(arr, arr + n, x - arr[i]) - arr;
            int l2 = arr[j];

            if (i == j) {
                continue;
            }

            if (l1 + l2 == x) {
                answer[0] = l1;
                answer[1] = l2;
                
                break;
            }
        }

        if (answer[0] == -1) {
            cout << "danger" << '\n';
        } else {
            cout << "yes " << answer[0] << ' ' << answer[1] << '\n';
        }
    }
}