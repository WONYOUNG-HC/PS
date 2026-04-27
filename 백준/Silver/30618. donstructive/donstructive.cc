#include <iostream>

using namespace std;

int n;
int arr[200010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int cnt, left, right;

    if (n % 2 == 0) {
        cnt = 0;
        left = n / 2 - 1;
        right = n / 2;
    } else {
        arr[n / 2] = n;
        cnt = 1;
        left = n / 2 - 1;
        right = n / 2 + 1;
    }

    while (cnt < n) {
        arr[left] = n - cnt;
        cnt += 1;
        left -= 1;

        arr[right] = n - cnt;
        cnt += 1;
        right += 1;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}