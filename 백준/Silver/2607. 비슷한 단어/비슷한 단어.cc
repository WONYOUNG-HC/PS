#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string arr[110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int table[100];
    fill(table, table + 100, 0);
    for (char c : arr[0])
        table[c]++;

    int ans = 0;
    for (int i = 1; i < n; i++) {
        int chk[100];
        fill(chk, chk + 100, 0);

        for (char c : arr[i])
            chk[c]++;

        int dif = 0;
        for (char c = 'A'; c <= 'Z'; c++) {
            if (table[c] != chk[c])
                dif += abs(table[c] - chk[c]);

            if (dif > 2)
                break;
        }

        if (dif < 2 || (arr[0].length() == arr[i].length() && dif == 2))
            ans++;
    }

    cout << ans;
}