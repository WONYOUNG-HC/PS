#include <iostream>
#include <algorithm>

using namespace std;

int immigration[100000];

long long MinTime(int n, int m);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> immigration[i];

    cout << MinTime(n, m);
}

bool Decision(int n, int m, long long mid) {
    long long cnt = 0;

    for (int i = 0; i < n; i++) {
        cnt += mid / immigration[i];

        if (cnt >= m)
            return true;
    }

    return cnt >= m;
}

long long MinTime(int n, int m) {
    long long left = *min_element(immigration, immigration + n);
    long long right = left * m;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (Decision(n, m, mid))
            right = mid - 1;
        else
            left = mid + 1;
    }

    return left;
}