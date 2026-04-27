#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int ans = 100;
    for (int i = 0; i <= b.size() - a.size(); i++) {
        int cur = 0;

        for (int j = 0; j < a.size(); j++) {
            if (a[j] != b[i + j]) cur++;
        }

        if (cur < ans) ans = cur;
    }

    cout << ans;
}