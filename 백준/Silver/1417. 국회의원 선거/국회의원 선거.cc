#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    int candidate[n + 2];
    for (int i = 0; i < n; i++)
        cin >> candidate[i];
    candidate[n] = 0; candidate[n + 1] = 0;

    int ans = 0;
    bool flag = true;
    while (flag) {
        flag = false;

        int* p = max_element(candidate + 1, candidate + n);

        if (candidate[0] <= *p) {
            candidate[0]++;
            (*p)--;
            ans++;
            flag = true;
        }
    }

    cout << ans;
}