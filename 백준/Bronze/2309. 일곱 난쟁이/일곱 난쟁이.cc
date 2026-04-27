#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int arr[9];
bool vis[9];

void f(int idx, int cnt, int sum) {
    if (cnt == 7) {
        if (sum == 100) {
            for (int i = 0; i < 9; i++) {
                if (vis[i]) {
                    cout << arr[i] << '\n';
                }
            }

            exit(0);
        }

        return;
    } 

    for (int i = idx; i < 9; i++) {
        if (vis[i]) {
            continue;
        }

        vis[i] = true;
        f(idx + 1, cnt + 1, sum + arr[i]);
        vis[i] = false;
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + 9);

    f(0, 0, 0);
}