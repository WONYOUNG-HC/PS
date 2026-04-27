#include <iostream>
#include <algorithm>

using namespace std;

int d, p;
int arr[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> d >> p;
    for (int i = 0; i < p; i++) {
        int l, c;
        cin >> l >> c;

        if (l > d)
            continue;

        arr[l] = max(arr[l], c);
        for (int j = d; j - l > 0; j--) {
            arr[j] = max(arr[j], min(arr[j - l], c));
        }
    }

    cout << arr[d];
}