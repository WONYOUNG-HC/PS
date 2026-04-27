#include <iostream>
#include <vector>

#define MOD 1'000'000

using namespace std;

int Decipher(string& cipher);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string cipher;
    cin >> cipher;

    cout << Decipher(cipher);
}

int Decipher(string& cipher) {
    int n = (int)cipher.size();
    cipher.insert(0, "9");
    cipher += '9';

    if (cipher[1] == '0')
        return 0;

    vector<int> dp(n + 1, 1);

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1];

        if (cipher[i] == '0' && (cipher[i-1] > '2' || cipher[i-1] == '0'))
            return 0;


        if (cipher[i-1] != '0' && cipher[i] != '0' && cipher[i+1] != '0' && \
        (cipher[i-1] == '1' || (cipher[i-1] == '2' && cipher[i] <= '6')))
            dp[i] += dp[i-2];

        dp[i] %= MOD;
    }

    return dp[n];
}