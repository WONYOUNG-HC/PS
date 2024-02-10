#include <iostream>
#include <string>

using namespace std;
using pii = pair<int, int>;

int n;
string k, s;

int main() {
    cin >> k >> s >> n;
    for (int i = 0; i < n; i++) {
        string dir;
        cin >> dir;

        pii dr = {0, 0};
        for (char d : dir) {
            if (d == 'R')
                dr.first = 1;
            else if (d == 'L')
                dr.first = -1;
            else if (d == 'T')
                dr.second = 1;
            else    
                dr.second = -1;
        }

        string nk = k;
        nk[0] += dr.first;
        nk[1] += dr.second;

        if (nk[0] < 'A' || nk[0] > 'H' || nk[1] < '1' || nk[1] > '8')
            continue;

        if (nk == s) {
            string ns = s;
            ns[0] += dr.first;
            ns[1] += dr.second;

            if (ns[0] < 'A' || ns[0] > 'H' || ns[1] < '1' || ns[1] > '8')
                continue;

            s = ns;
        }

        k = nk;
    }

    cout << k << '\n' << s;
}