#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int dist[n-1];
    for (int i=0; i<n-1; i++)
        cin >> dist[i];

    long long gas[n];
    for (int i=0; i<n-1; i++)
        cin >> gas[i];

    long long ans =0;
    long long price = 1000000000;
    for (int i=0; i<n-1; i++) {
        if (gas[i] < price) price = gas[i];

        ans += dist[i] * price;
    }

    cout << ans;
}