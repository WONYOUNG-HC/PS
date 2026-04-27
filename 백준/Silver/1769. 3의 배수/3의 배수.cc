#include <iostream>
#include <string>

using namespace std;

int main() {
    string s; cin >> s;

    int cnt = 0;
    while (s.length() != 1) {
        int sum = 0;
        for (char c: s)
            sum += atoi(&c);
        s = to_string(sum), cnt++;
    }

    cout << cnt << '\n' << (stoi(s) % 3 ? "NO" : "YES");
}