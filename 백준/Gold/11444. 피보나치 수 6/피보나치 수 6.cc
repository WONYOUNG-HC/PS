#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

typedef long long ll;

const ll MOD = 1000000007;

matrix mul(matrix a, matrix b) {
    matrix c = {{0, 0}, {0, 0}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }

    return c;
}

matrix pow(matrix m, ll n) {
    if (n == 1) {
        return m;
    }

    if (n % 2 == 0) {
        matrix v = pow(m, n / 2);

        return mul(v, v);
    }

    matrix v = pow(m, (n - 1) / 2);

    return mul(m, mul(v, v));
}

int main() {
    ll n;
    cin >> n;

    cout << pow({{1, 1}, {1, 0}}, n)[1][0];
}