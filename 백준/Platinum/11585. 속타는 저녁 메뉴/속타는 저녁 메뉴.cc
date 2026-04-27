#include <iostream>
#include <string>

using namespace std;

int n;
char p[1000010];
char s[2000010];
int pi[1000010];

void make_pi() {
    int j = 0;

    for (int i = 1; i < n; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }

        if (p[i] == p[j]) {
            j += 1;
            pi[i] = j;
        }
    }
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = n; i < n * 2; i++) {
        s[i] = s[i - n];
    }

    make_pi();

    int cnt = 0;
    int j = 0;

    for (int i = 0; i < n * 2 - 1; i++) {
        while (j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }

        if (s[i] == p[j]) {
            if (j == n - 1) {
                cnt += 1;
                j = pi[j];
            } else {
                j += 1;
            }
        }
    }
    
    int divisor = gcd(cnt, n);

    cout << cnt / divisor << '/' << n / divisor;
}
