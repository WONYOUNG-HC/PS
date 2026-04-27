#include <iostream>

#define M 1000

using namespace std;

class MatrixPow {
public:
    static int n;
private:
    int matrix[5][5]{};
public:
    void SetMatrix();
    MatrixPow operator*(const MatrixPow& arg) const;
    MatrixPow& operator=(const MatrixPow& arg);
    MatrixPow& Modulo();
    friend void operator<<(ostream& os, const MatrixPow& mp);
};
int MatrixPow::n = 0;

MatrixPow Power(MatrixPow& mp, long long b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long b;
    cin >> MatrixPow::n >> b;
    MatrixPow mp;
    mp.SetMatrix();

    cout << Power(mp, b);
}

pair<long long, MatrixPow> memoization;

MatrixPow Power(MatrixPow& mp, long long b) {
    if (b == 1)
        return mp.Modulo();

    if (b % 2 == 0) {
        if (memoization.first == b)
            return memoization.second;

        MatrixPow ret = Power(mp, b/2) * Power(mp, b/2);
        memoization.first = b;
        memoization.second = ret;
        return ret;
    }
    else {
        if (b == memoization.first)
            return memoization.second;

        MatrixPow ret = Power(mp, (b-1)/2) * Power(mp, (b-1)/2) * mp;
        memoization.first = b;
        memoization.second = ret;
        return ret;
    }
}


void MatrixPow::SetMatrix() {
    for (int i=0; i<MatrixPow::n; i++)
        for (int j=0; j<MatrixPow::n; j++)
            cin >> matrix[i][j];
}


MatrixPow MatrixPow::operator*(const MatrixPow& arg) const {
    MatrixPow ret;
    for (int i=0; i<MatrixPow::n; i++) {
        for (int j=0; j<MatrixPow::n; j++) {
            for (int k=0; k<MatrixPow::n; k++) {
                ret.matrix[i][j] += this->matrix[i][k] * arg.matrix[k][j];
            }
            ret.matrix[i][j] %= M;
        }
    }
    return ret;
}

MatrixPow& MatrixPow::operator=(const MatrixPow& arg) {
    for (int i=0; i<MatrixPow::n; i++)
        for (int j=0; j<MatrixPow::n; j++)
            this->matrix[i][j] = arg.matrix[i][j];

    return *this;
}

MatrixPow& MatrixPow::Modulo() {
    for (int i=0; i<MatrixPow::n; i++)
        for (int j=0; j<MatrixPow::n; j++)
            matrix[i][j] %= M;

    return *this;
}

void operator<<(ostream& os, const MatrixPow& mp) {
    for (int i=0; i<MatrixPow::n; i++) {
        for (int j=0; j<MatrixPow::n; j++) {
            os << mp.matrix[i][j] << ' ';
        }
        os << '\n';
    }
}
