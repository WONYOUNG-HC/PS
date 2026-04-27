#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int lope[n];
    for (int i=0; i<n; i++)
        cin >> lope[i];
    sort(lope, lope+n);

    int ans = 0;
    for (int i=0; i<n; i++) {
        int weight = lope[i] * (n-i);
        if (weight > ans) ans = weight;
    }

    cout << ans;
}