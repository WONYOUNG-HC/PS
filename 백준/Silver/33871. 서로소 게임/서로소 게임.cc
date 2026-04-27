#include <iostream>

using namespace std;

int x;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }

    return gcd(b, a % b);
}

int main() {
    cin >> x;

    cin >> x;

    int ans = 1;

    while (true) {
        int y = 0;
        
        for (int i = 2; i < x; i++) {
            int d = gcd(x, i);

            if (d == 1) {
                y = i;

                break;
            }
        }

        if (y == 0) {
            break;
        }

        x = y;
        ans = (ans + 1) % 2;
    }

    cout << (ans == 0 ? "Soomin" : "Song");
}