#include <iostream>

using namespace std;

int n, t;
int arr[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> t;

    for (int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
    }

    int cur = 0;

    for (int i = 0; i < t; i++) {
        int b;

        cin >> b;

        cur = (cur + b - 1) % (2 * n);

        cout << arr[cur] << ' ';
    }
}