#include <iostream>
#include <algorithm>
#include <cmath>

#define ll long long
#define pll pair<ll, ll>
#define X first
#define Y second

using namespace std;

pll arr[4];

ll dist(pll a, pll b) {
    return pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2);
}

bool solve() {
    for (pll& pr : arr)
        cin >> pr.X >> pr.Y;

    sort(arr, arr + 4);

    ll d = dist(arr[0], arr[1]);

    if (d != dist(arr[0], arr[2]))
        return false;

    if (d != dist(arr[1], arr[3]))
        return false;

    if (d != dist(arr[2], arr[3]))
        return false;

    if (dist(arr[0], arr[3]) != dist(arr[1], arr[2]))
        return false;

    return true;
}

int main() {
    int tc; cin >> tc;
    while (tc--)
        cout << solve() << '\n';
}