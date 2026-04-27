#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
string arr[101];

int main() {
    cin >> n;

    int q = -1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == "?")
            q = i;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        
        if (n == 1) {
            cout << s;
            break;
        }

        if (find(arr, arr + n, s) != arr + n)
            continue;

        if (0 < q && q < n - 1 && s[0] == *(arr[q - 1].end() - 1) && *(s.end() - 1) == arr[q + 1][0]) {
            cout << s;
            break;
        }

        if (q == 0 && *(s.end() - 1) == arr[1][0]) {
            cout << s;
            break;
        }

        if (q == n - 1 && s[0] == *(arr[n - 2].end() - 1)) {
            cout << s;
            break;
        }
    }
}