#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int n;
ll arr[100010];
ll prefix[100010];

ll sum(int left, int right) {
    return prefix[right] - prefix[left - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];

        prefix[i] = arr[i] + prefix[i - 1];
    }

    vector<int> st;
    ll ans = 0;

    st.push_back(0);

    for (int i = 1; i <= n + 1; i++) {
        while (arr[st.back()] > arr[i]) {
            int left = st[st.size() - 2] + 1;
            int right = i - 1;

            ans = max(ans, sum(left, right) * arr[st.back()]);

            st.pop_back();
        }

        st.push_back(i);
    }

    cout << ans;
}