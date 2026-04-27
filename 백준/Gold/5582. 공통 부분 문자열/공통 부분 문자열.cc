#include <iostream>
#include <cstring>

using namespace std;

char a[4010]{' '}, b[4010]{' '};
int dp[4010][4010];

int main() {
    cin >> a + 1 >> b + 1;
    int la = strlen(a), lb = strlen(b);

    int ans = 0;
    for (int i = 1; i < la; i++) {
        for (int j = 1; j < lb; j++ ) {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
}