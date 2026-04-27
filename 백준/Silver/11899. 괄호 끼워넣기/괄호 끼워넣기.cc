#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str;
    cin >> str;

    int ans = 0;
    stack<char> s;
    for (char c : str) {
        if (c == '(')
            s.push('(');
        else if (s.empty())
            ans++;
        else
            s.pop();
    }

    ans += s.size();
    cout << ans;
}