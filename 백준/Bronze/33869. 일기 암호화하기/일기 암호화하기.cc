#include <iostream>
#include <string>

using namespace std;

string w, s;
char arr[127];
bool vis[127];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> w >> s;

    char idx = 'A';

    for (char c : w) {
        if (vis[c]) {
            continue;
        }

        arr[idx] = c;
        vis[c] = true;
        idx += 1;
    }

    char k = 'A';

    while (idx <= 'Z') {
        while (vis[k]) {
            k += 1;
        }

        arr[idx] = k;
        idx += 1;
        k += 1;
    }

    for (char c : s) {
        cout << arr[c];
    }
}