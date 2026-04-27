#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b;
    cin >> a >> b;

    int cnt = 1;
    while (a < b) {
        if (b % 2 == 0)
            b /= 2;
        else if (b % 10 == 1)
            b /= 10;
        else
            break;
            
        cnt++;
    }

    a == b ? cout << cnt : cout << -1;
}