#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

string str;
stack<pii> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str;

    for (char c : str) {
        if (c == '(') {
            st.push({-1, -1});
        } else if (c == ')') {
            int len = 0;
            int last = st.top().second;

            while (st.top() != make_pair(-1, -1)) {
                len += st.top().first;
                
                st.pop();
            }

            st.pop();

            len *= st.top().second;

            st.pop();

            if (last != -1) {
                st.push({len, last});
            }
        } else {
            st.push({1, c - '0'});
        }
    }

    int ans = 0;

    while (!st.empty()) {
        ans += st.top().first;
        st.pop();
    }

    cout << ans;
}