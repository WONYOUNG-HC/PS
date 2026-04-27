#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cin >> str;

    int count[26]{};

    for (char c : str)
        count[c - 'A']++;

    int odd = -1;
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0 && odd == -1)
            odd = i;
        else if (count[i] % 2 != 0 && odd != -1) {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }

    string ans;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0 && i != odd)
            ans.append(count[i] / 2, 'A' + i);
        else if (i == odd)
            ans.append((count[i] - 1) / 2, 'A' + i);
    }

    cout << ans;

    if (odd != -1) cout << (char)('A' + odd);

    reverse(ans.begin(), ans.end());

    cout << ans;
}