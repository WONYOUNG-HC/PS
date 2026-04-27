#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    int arr[n + 1];
    arr[0] = 0;

    for (int i = 1; i <= n; i++) {
        arr[i] = -1;
        if (i - 5 >= 0 && arr[i - 5] != -1)
            arr[i] = arr[i - 5] + 1;
        else if (i - 2 >= 0 && arr[i - 2] != -1)
            arr[i] = arr[i - 2] + 1;
    }

    cout << arr[n];
}