#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;

    string str[n];
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        max_len = max(max_len, (int)str[i].size());
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < max_len - str[i].size(); j++)
            str[i].insert(str[i].begin(), max_len - str[i].size(),'\0');
    }

    pair<int, char> table[26];
    for (int i = 0; i < 26; i++)
        table[i] = {0, 'A' + i};

    for (int i = 0; i < n; i++) {
        int k = 1;
        for (int j = max_len - 1; j >= 0; j--) {
            if (str[i][j] == '\0')
                break;

            table[str[i][j] - 'A'].first += k;
            k *= 10;
        }
    }

    sort(table, table + 26, greater<>());

    int value[26];
    int cur = 9;
    for (int i = 0; i < 10; i++) {
        value[table[i].second - 'A'] = cur--;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int k = 1;
        for (int j = max_len - 1; j >= 0; j--) {
            if (str[i][j] == '\0')
                break;

            sum += value[str[i][j] - 'A'] * k;
            k *= 10;
        }
    }

    cout << sum;
}