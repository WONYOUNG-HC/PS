#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string line;
    cin >> line;

    vector<bool> burger(n);
    for (int i = 0; i < n; i++)
        if (line[i] == 'H') burger[i] = true;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (line[i] == 'H')
            continue;

        bool flag = false;
        int j = i - k;
        while (j < i) {
            while (j < 0) j++;

            if (line[j] == 'H' && burger[j]) {
                ans++;
                burger[j] = false;
                flag = true;
                break;
            }
            j++;
        }

        if (flag) continue;

        j = i + 1;
        while (j < n && j - k <= i) {
            if (line[j] == 'H' && burger[j]) {
                ans++;
                burger[j] = false;
                break;
            }
            j++;
        }
    }

    cout << ans;
}