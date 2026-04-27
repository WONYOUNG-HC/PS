#include <iostream>
#include <algorithm>

using namespace std;

int n;
string arr[10010];

bool solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < n - 1; i++) {
        if (arr[i].compare(0, arr[i].length(), arr[i + 1], 0, arr[i].length()) == 0)
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--)
        cout << (solve() ? "YES" : "NO") << '\n';
}