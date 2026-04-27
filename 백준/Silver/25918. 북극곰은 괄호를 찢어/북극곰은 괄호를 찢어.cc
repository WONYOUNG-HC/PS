#include <iostream>
#include <stack>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    stack<char> st;
    int mx_size = 0;

    for (int i = 0; i < n; i++) {
        char c;

        cin >> c;

        if (st.empty()) {
            st.push(c);
        } else if (st.top() == ')' && c == '(') {
            st.pop();
        } else if (st.top() == '(' && c == ')') {
            st.pop();
        } else {
            st.push(c);
        }

        mx_size = max(mx_size, (int)st.size());
    }

    int ans = -1;

    if (st.empty()) {
        ans = mx_size;
    }

    cout << ans;
} 