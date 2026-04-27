#include <iostream>

using namespace std;

int k, arr[50], ans[6];

void recur(int cnt, int pos) {
    if (cnt == 6) {
        for (int x : ans)
            cout << x << ' ';
        cout << '\n';

        return;
    }

    for (int i = pos; i < k; i++) {
        ans[cnt] = arr[i];
        recur(cnt + 1, i + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> k;

        if (k == 0)
            break;

        for (int i = 0; i < k; i++)
            cin >> arr[i];

        recur(0, 0);
        cout << '\n';
    }
}