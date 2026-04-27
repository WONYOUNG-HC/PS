#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        m > 300 && (m = 300); m < 250 && (m = 249);
        cout << 4 - (m / 25 - 9) << ' ';
    }
}