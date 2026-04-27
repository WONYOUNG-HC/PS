#include <iostream>
#include <string>

using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        string s; cin >> s;
        cout << s.front() << s.back() << '\n';
    }
}