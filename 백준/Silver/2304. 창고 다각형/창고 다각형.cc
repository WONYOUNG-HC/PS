#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n;
pii arr[1010];
stack<pii> st1, st2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr + n);

    //
    //
    //

    st1.push(arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i].second >= st1.top().second) {
            st1.push(arr[i]);
        }
    }

    st2.push(arr[n - 1]);

    for (int i = 2; i <= n; i++) {
        if (arr[n - i].second > st2.top().second) {
            st2.push(arr[n - i]);
        }
    }

    //
    //
    //

    int ans = st1.top().second;

    pii prev = st1.top();
    st1.pop();

    while (!st1.empty()) {
        ans += (prev.first - st1.top().first) * st1.top().second;

        prev = st1.top();
        st1.pop();
    }

    prev = st2.top();
    st2.pop();

    while (!st2.empty()) {
        ans += (st2.top().first - prev.first) * st2.top().second;

        prev = st2.top();
        st2.pop();
    }

    cout << ans;
}