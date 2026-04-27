#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;

    string prv, nxt; cin >> prv;
    for (int i = 1; i < n; i++) {
        cin >> nxt;

        for (int j = 0; j < nxt.length(); j++) {
            if (prv[j] != nxt[j])
                nxt[j] = '?';
        }

        prv = nxt;
    }

    cout << prv;
}