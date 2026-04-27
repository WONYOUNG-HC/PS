#include <iostream>
#include <stack>

using namespace std;

string str;

int solve() {
    stack<int> s;
    for (char c : str) {
        if (c == ')' || c == ']') {
            int score = 0;
            while (!s.empty() && s.top() > 0) {
                score += s.top();
                s.pop();
            }

            if (s.empty()) {
                return 0;
            }
            else if ((c == ')' && s.top() == -2) || (c == ']' && s.top() == -3)) {
                int t = -s.top();
                !score && score++;
                s.pop();
                s.push(t * score);
            }
            else {
                return 0;
            }
        }
        else {
            s.push(c == '(' ? -2 : -3);
        }
    }

    int ans = 0;
    while (!s.empty()) {
        if (s.top() < 0)
            return 0;
        
        ans += s.top();
        s.pop();
    }

    return ans;
}

int main() {
    cin >> str;
    cout << solve();
}