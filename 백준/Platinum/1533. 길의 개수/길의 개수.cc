#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using vvl = vector<vector<ll>>;

const ll mod = 1000003;
const int mat_size = 50;

int n, s, e, t;
vvl mat = vector<vector<ll>>(mat_size, vector<ll>(mat_size));

int v(int i, int j) {
    return n + (4 * i) + j;
}

vvl mat_mul(vvl a, vvl b) {
    vvl ret = vector<vector<ll>>(mat_size, vector<ll>(mat_size));

    for (int i = 0; i < mat_size; i++) {
        for (int j = 0; j < mat_size; j++) {
            for (int k = 0; k < mat_size; k++) {
                ret[i][j] += a[i][k] * b[k][j];
                ret[i][j] %= mod;
            }
        }
    }

    return ret;
}

vvl mat_pow(vvl base, int exp) {
    if (exp == 1) {
        return base;
    }

    vvl value = mat_pow(base, exp / 2);

    if (exp % 2 == 0) {
        return mat_mul(value, value);
    }

    return mat_mul(mat_mul(value, value), base);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s >> e >> t;

    for (int i = 0; i < n; i++) {
        string input;

        cin >> input;

        for (int j = 0; j < n; j++) {
            mat[i][j] = input[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4 - 1; j++) {
            mat[v(i, j)][v(i, j + 1)] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] >= 2) {
                mat[i][v(i, 0)] = 1;
                mat[v(i, mat[i][j] - 2)][j] = 1;
                mat[i][j] = 0;
            }
        }
    }

    vvl ans = mat_pow(mat, t);

    cout << ans[s - 1][e - 1];
}
