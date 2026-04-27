#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int na, nb;
    cin >> na >> nb;

    set<int> a, b, c;
    for (int i = 0; i < na; i++) {
        int x; cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < nb; i++) {
        int x; cin >> x;
        b.insert(x);
    }

    for (int x : a) {
        if (b.find(x) == b.end())
            c.insert(x);
    }

    cout << c.size() << '\n';
    for (int x : c)
        cout << x << ' ';
}