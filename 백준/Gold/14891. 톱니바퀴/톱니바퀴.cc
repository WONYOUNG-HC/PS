#include <iostream>

#define N 0
#define E 2
#define S 4
#define W 6

using namespace std;

class Wheel {
public:
    char pole[9];
    int rotate;

    void left() {
        char t = pole[0];
        for (int i = 0; i < 7; i++) {
            pole[i]= pole[i + 1];
        }
        pole[7] = t;
    }

    void right() {
        char t = pole[7];
        for (int i = 7; i > 0; i--) {
            pole[i] = pole[i - 1];
        }
        pole[0] = t;
    }
};

Wheel w[4];

void f(int n, int r) {
    if (n != 0 && w[n].pole[W] != w[n - 1].pole[E] && w[n - 1].rotate == 0) {
        w[n - 1].rotate = r * -1;
        f(n - 1, r * -1);
    }

    if (n != 3 && w[n].pole[E] != w[n + 1].pole[W] && w[n + 1].rotate == 0) {
        w[n + 1].rotate = r * -1;
        f(n + 1, r * -1);
    }

    r == 1 ? w[n].right() : w[n].left();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (auto& x : w)
        cin >> x.pole;

    int k; cin >> k;
    while (k--) {
        int a, b;
        cin >> a >> b;

        w[a - 1].rotate = b;
        f(a - 1, b);

        for (int i = 0; i < 4; i++)
            w[i].rotate = 0;
    }

    int p = 1, ans = 0;
    for (int i = 0; i < 4; i++) {
        if (w[i].pole[N] == '1')
            ans += p;
        p *= 2;
    }

    cout << ans;
}