#include <iostream>
#include <string>

using namespace std;

int n, k, ans;
int arr[60], vis;

void f(int idx, int cnt) {
    if (cnt == k - 5) {
        int r = 0;
        for (int i = 0; i < n; i++) {
            (arr[i] & vis) == arr[i] && r++;
        }

        ans = max(ans, r);
        return;
    }

    for (int i = idx; i <= 'z'; i++) {
        int bit = 1 << (i - 'a');
        if (vis & bit)
            continue;
        
        vis |= bit;
        f(i + 1, cnt + 1);
        vis &= ~bit;
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (char c : s)
            arr[i] |= 1 << (c - 'a');
    }
    
    if (k < 5) {
        cout << 0;
        return 0;
    }

    if (k == 26) {
        cout << n;
        return 0;
    }

    char init[5] = {'a', 'n', 't', 'c', 'i'};
    for (char c : init)
         vis |= 1 << (c - 'a'); 

    f('b', 0);
    cout << ans;
}