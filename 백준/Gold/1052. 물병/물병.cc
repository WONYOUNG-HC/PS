#include <iostream>

using namespace std;

int n, k;

int f() {
    int a = n, ret = 0;

    while (a) {
        a & 1 && ret++;
        a >>= 1;
    }

    return ret;
}

int main() {
    cin >> n >> k;

    int ans = 0;
    while (f() > k) 
        n++, ans++;
    
    cout << ans;
}