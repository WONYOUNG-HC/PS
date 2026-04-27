#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n;
string s, e, q;
pair<string, string> arr[100010];
set<string> before, after;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> e >> q;

    string a, b;
    while (cin >> a >> b) 
        arr[n++] = {a, b};

    sort(arr, arr + n, [](const pair<string, string>& left, const pair<string, string>& right) -> bool {
        return lexicographical_compare(left.first.begin(), left.first.end(), right.first.begin(), right.first.end());
    });

    int idx = 0;
    while (!lexicographical_compare(s.begin(), s.end(), arr[idx].first.begin(), arr[idx].first.end()))
        before.insert(arr[idx++].second);

    while (lexicographical_compare(arr[idx].first.begin(), arr[idx].first.end(), e.begin(), e.end()))
        idx++;

    while (idx < n && !lexicographical_compare(q.begin(), q.end(), arr[idx].first.begin(), arr[idx].first.end()))
        after.insert(arr[idx++].second);

    int ans = 0;
    for (string str : after)
        before.find(str) != before.end() && ans++;

    cout << ans;
}