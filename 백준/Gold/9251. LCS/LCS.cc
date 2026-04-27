#include <iostream>
#include <cstring>
using namespace std;

int main(void) {

    char str1[1001];
    char str2[1001];

    cin >> str1 >> str2;

    int n = strlen(str1) + 1;
    int m = strlen(str2) + 1;

    int dp[n][m];

    for(int i=0; i<m; i++)
        dp[0][i] = 0;

    for(int i=0; i<n; i++)
        dp[i][0] = 0;

    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else {
                if(dp[i-1][j] > dp[i][j-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-1];    
            }
        }
    }       

    cout << dp[n-1][m-1] << '\n'; 

    return 0;
}