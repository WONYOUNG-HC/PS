#include <iostream>
#include <set>

using namespace std;

int n;
string str;
set<string> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> str;

        if (str == "ENTER") {
            s.clear();
            continue;
        }
        
        s.find(str) == s.end() && ans++;
        s.insert(str);
    }

    cout << ans;
}