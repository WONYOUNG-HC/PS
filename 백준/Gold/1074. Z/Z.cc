#include <iostream>
#include <cmath>

using namespace std;

int k, cnt;

void Z(int r, int c) {
    k /= 2;

    if (k == 1) {
        if (r == 0 && c == 1) cnt += 1;
        else if (r == 1 && c == 0) cnt += 2;
        else if (r == 1 && c == 1) cnt += 3;
        return;
    }

    if (r < k && c < k) {
        Z(r, c);
    }
    else if (r < k && c >= k) {
        cnt += pow(k, 2);
        Z(r, c-k);
    }
    else if (r >= k && c < k) {
        cnt += pow(k, 2) * 2;
        Z(r-k, c);
    }
    else if (r >= k && c >= k) {
        cnt += pow(k, 2) * 3;
        Z(r-k, c-k);
    }
}

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    k = pow(2, n);
    Z(r, c);
    cout << cnt;
}