#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> palindrome;

void CheckPalindrome(string& str, int len);
int DividePalindrome(int len);

int main() {
    string str; cin >> str;
    str.insert(str.begin(), ' ');
    int len = (int)str.size();

    CheckPalindrome(str, len);

    cout << DividePalindrome(len);
}

void CheckPalindrome(string& str, int len) {
    palindrome.resize(len, vector<bool>(len));

    for (int i = 1; i < len; i++) {
        palindrome[i][i] = true;

        if (i < len - 1 && str[i+1] == str[i])
            palindrome[i][i+1] = true;
    }

    for (int diag = 2; diag < len; diag++) {
        for (int i = 1; i + diag < len; i++) {
            int j = i + diag;

            if (palindrome[i+1][j-1] && str[i] == str[j])
                palindrome[i][j] = true;
        }
    }
}

int DividePalindrome(int len) {
    vector<int> dp(len, 1e9);

    dp[0] = 0;
    for (int i = 1; i < len; i++) {
        for (int j = 1; j <= i; j++) {
            if (palindrome[j][i])
                dp[i] = min(dp[i], dp[j-1] + 1);
        }
    }

    return dp[len-1];
}