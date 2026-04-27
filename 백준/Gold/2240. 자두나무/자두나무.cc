#include <iostream>
#include <algorithm>

using namespace std;

int t, w;
int arr[1010];
int dp[1010][40][2];

int f(int cur, int cnt, int pos) {
    if (dp[cur][cnt][pos] >= 0)
        return dp[cur][cnt][pos];
    
    int &ret = dp[cur][cnt][pos] = 0;
    ret = (pos + 1 == arr[cur]);
    
    if (cur == t) 
        return ret;

    if (cnt == w) 
        return ret += f(cur + 1, cnt, pos);

    return ret += max(f(cur + 1, cnt + 1, !pos), f(cur + 1, cnt, pos));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t >> w;
    for (int i = 1; i <= t; i++)
        cin >> arr[i];
    
    fill_n(&dp[0][0][0], 1010 * 40 * 2, -1);
    cout << f(0, 0, 0);
}