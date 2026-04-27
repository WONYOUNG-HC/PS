#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int ans = 0;

    vector<int> st;
    st.push_back(0);

    for (int i = 1; i <= n + 1; i++) {
        while (arr[i] < arr[st.back()]) {
            int top = arr[st.back()];
            st.pop_back();

            int area = top * (i - (st.back() + 1));

            ans = max(ans, area);
        }

        st.push_back(i);
    }

    cout << ans;
}