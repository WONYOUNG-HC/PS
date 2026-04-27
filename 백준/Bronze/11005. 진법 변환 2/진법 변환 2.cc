#include <iostream>
#include <algorithm>

using namespace std;

char f(int x) {
    if (x < 10)
        return '0' + x;
    return 'A' + x - 10;
}

int main() {
    int n, b;
    cin >> n >> b;

    string ans;
    while (n >= b) {
        ans += f(n % b);
        n /= b;
    }
    ans += f(n);

    reverse(ans.begin(), ans.end());
    cout << ans;
}