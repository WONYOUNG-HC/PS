#include <iostream>

using namespace std;
using pii = pair<int, int>;

int n;
pii arr[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;   
    
    for (int i = 1; i < n; i++) {
        if (arr[i].first < arr[i - 1].second) {
            arr[i].first = arr[i - 1].first;
            arr[i].second = max(arr[i].second, arr[i - 1].second);  
            arr[i - 1] = {0, 0};
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) 
        ans += arr[i].second - arr[i].first;

    cout << ans;
}