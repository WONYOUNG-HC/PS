#include <iostream>
#include <string>

using namespace std;

int main() {
    string today; int n;
    cin >> today >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        string day; cin >> day;
        day >= today && (ans++);
    }

    cout << ans;
}