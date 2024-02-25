#include <iostream>

using namespace std;

int s, c;
int arr[1000010];

bool f(int mid) {
    int cnt = 0;
    for (int i = 0; i < s; i++) 
        cnt += arr[i] / mid;

    return cnt >= c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> c;
    for (int i = 0; i < s; i++) 
        cin >> arr[i];
    
    int left = 1, right = 1e9;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (f(mid))
            left = mid + 1;
        else 
            right = mid - 1;
    }

    int cnt = 0;
    long long ans = 0;
    for (int i = 0; i < s; i++) {
        while (arr[i] >= right) {
            if (cnt == c)
                break;
            
            cnt++;
            arr[i] -= right;
        }

        ans += arr[i];
    }

    cout << ans;
}