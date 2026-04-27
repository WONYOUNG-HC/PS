#include <iostream>

using namespace std;

int n;
int arr[10][1010];

int main() {
    cin >> n;

    for (int i = 0; i < 10; i++)
        arr[i][1] = 1;
    for (int i = 0; i <= n; i++)
        arr[0][i] = 1;
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < 10; j++) {
            arr[j][i] = (arr[j - 1][i] + arr[j][i - 1]) % 10007;
        }        
    }

    int ans = 0;
    for (int i = 0; i < 10; i++)
        ans += arr[i][n];

    cout << ans % 10007;
}