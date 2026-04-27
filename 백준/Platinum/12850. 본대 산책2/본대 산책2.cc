#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using vvl = vector<vector<ll>>;

const ll MOD = 1000000007;
int n;

vvl multiply(vvl a, vvl b) {
    vvl res(a.size(), vector<ll>(b[0].size(), 0));

    for (int k = 0; k < b.size(); k++) {
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b[0].size(); j++) {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j])) % MOD;
            }
        }
    }

    return res;
}

vvl power(vvl mat, int k) {
    if (k == 1) {
        return mat;
    }

    if (k % 2 == 0) {
        vvl res = power(mat, k / 2);

        return multiply(res, res);
    }

    vvl res = power(mat, (k - 1) / 2);

    return multiply(multiply(res, res), mat);
}

int main() {
    cin >> n;

    vvl matrix = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 0}
    };

    cout << power(matrix, n)[0][0];
}