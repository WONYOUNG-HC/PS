#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int arr[n+1];
    arr[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    int start, end;
    for (int i=0; i<m; i++) {
        cin >> start >> end;
        cout << arr[end] - arr[start-1] << '\n';
    }
}