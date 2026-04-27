#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string arr[1010];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n, [](string a, string b) -> bool {
        string ab = a + b;
        string ba = b + a;

        return a + b > b + a;
    });

    if (arr[0][0] == '0') {
        cout << 0;
    } else {
        for (string s : arr) {
            cout << s;
        }
    }
}