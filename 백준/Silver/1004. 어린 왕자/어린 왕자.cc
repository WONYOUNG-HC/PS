#include <iostream>

#define pii pair<int, int>
#define X first
#define Y second

using namespace std;

int n;
pii pos[55]; int rad[55];

bool inCircle(pii& p, int i) {
    return (p.X - pos[i].X) * (p.X - pos[i].X) + (p.Y - pos[i].Y) * (p.Y - pos[i].Y) < rad[i] * rad[i];
}

void solve() {
    pii p1, p2;
    cin >> p1.X >> p1.Y >> p2.X >> p2.Y >> n;

    for (int i = 0; i < n; i++)
        cin >> pos[i].X >> pos[i].Y >> rad[i];

    int ans = 0;
    for (int i = 0; i < n; i++)
        (inCircle(p1, i) ^ inCircle(p2, i)) && ans++;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--)
        solve();
}