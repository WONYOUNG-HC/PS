#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;

    stack<char> st;
    int ans = 0;
    for (int i=0; i<m; i++) {
        if (!st.empty() && st.top() == str[i]) {
            if (st.size() >= (2*n)+1)
                ans += ((st.size()-1) / 2) + 1 - n;
            stack<char>().swap(st);
        }
        else if (!st.empty() && st.top() != str[i]){
            st.push(str[i]);
        }

        if (st.empty() && str[i] == 'I'){
            st.push('I');
        }
    }

    if (st.size() >= (2*n)+1)
        ans += ((st.size()-1) / 2) + 1 - n;

    cout << ans;
}