#include <iostream>
#include <map>

using namespace std;

int n, s;
int arr[50];
map<int, int> m;
long long ans;

void left(int cur, int sum) {
    if (cur == n / 2) {
        m[sum]++;
        return;
    }

    left(cur + 1, sum + arr[cur]);
    left(cur + 1, sum);
}

void right(int cur, int sum) {
    if (cur == n) {
        ans += m[s - sum];
        return;
    }

    right(cur + 1, sum + arr[cur]);
    right(cur + 1, sum);
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    left(0, 0);
    right(n / 2, 0);
    cout << ans - !s;
}