#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), greater<>());

    int sum = c;
    vector<int> ans = {c / a};
    for (int i = 0; i < n; i++) {
        sum += v[i];
        ans.push_back(sum / (a + b * (i + 1)));
    }

    cout << *max_element(ans.begin(), ans.end());
}