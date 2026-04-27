#include <iostream>
#include <vector>

using namespace std;

vector<int> gate;

void Init(int g);
bool Docking(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int g, p;
    cin >> g >> p;

    Init(g);
    for (int i=0; i<p; i++) {
        int n; cin >> n;

        if (!Docking(n)) {
            cout << i;
            return 0;
        }
    }

    cout << p;

    return 0;
}

void Init(int g) {
    gate.resize(g+1);
    for (int i=1; i<=g; i++)
        gate[i] = i;
}

int Find(int n) {
    if (n == gate[n])
        return n;

    return gate[n] = Find(gate[n]);
}

bool Docking(int n) {
    n = Find(n);
    if (n == 0)
        return false;

    int m = Find(n-1);
    gate[n] = m;

    return true;
}