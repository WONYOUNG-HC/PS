#include<iostream>

using namespace std;

int server[1010][1010];

bool Decision(int n, int mid, long long half) {
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt += (server[i][j] > mid ? mid : server[i][j]);

            if (cnt >= half) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    long long total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> server[i][j];
            total += server[i][j];
        }
    }

    long long half = (total % 2 == 0 ? total / 2 : (total / 2) + 1);

    int left = 0, right = 10000000;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (Decision(n, mid, half)) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << left;
}