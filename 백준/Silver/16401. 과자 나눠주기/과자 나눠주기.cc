#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> snack;

int DivideSnack(int n, int m);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    snack.resize(n);
    for (int i = 0; i < n; i++)
        cin >> snack[i];

    cout << DivideSnack(n, m);
}

bool Decision(int n, int m, int mid) {
    int cnt = 0, rem = 0;

    for (int i = 0; i < n ; i++) {
        if (snack[i] < mid)
            break;

        rem += (snack[i] >= 2 * mid ? (snack[i] / mid) - 1 : 0);
        cnt++;

        if (cnt == m)
            return true;
    }

    return cnt + rem >= m;
}

int DivideSnack(int n, int m) {
    sort(snack.begin(), snack.end(), greater<>());
    int left = 1, right = snack[0];

    while (left <= right) {
        int mid = (left + right) / 2;

        if (Decision(n, m, mid))
            left = mid + 1;

        else
            right = mid - 1;

    }

    return right;
}