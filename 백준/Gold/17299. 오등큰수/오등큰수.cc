#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int n;
int arr[1000010], cnt[1000010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    reverse(arr, arr + n);
    stack<int> st, ans;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && cnt[arr[i]] >= cnt[st.top()])
            st.pop();
        ans.push(st.empty() ? -1 : st.top());
        st.push(arr[i]);
    }

    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
}