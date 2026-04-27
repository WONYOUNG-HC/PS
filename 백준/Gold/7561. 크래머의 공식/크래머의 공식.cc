#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

const int n = 3;
vector<vector<long long>> a(n, vector<long long>(n));
vector<vector<long long>> rep_a[n];
vector<long long> b(n);

long long det(vector<vector<long long>> mat) {
    int l = mat.size();

    if (l == 1) {
        return mat[0][0];
    }

    long long ret = 0;

    for (int j = 0; j < l; j++) {
        vector<vector<long long>> minor;

        for (int r = 1; r < l; r++) {
            vector<long long> row;

            for (int c = 0; c < l; c++) {
                if (c == j) {
                    continue;
                }

                row.push_back(mat[r][c]);
            }

            minor.push_back(row);
        }

        ret += mat[0][j] * pow(-1, 1 + (j + 1)) * det(minor);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    cout << fixed;
    cout.precision(3);
    
    while (tc--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }

            cin >> b[i];
        }

        for (int i = 0; i < n; i++) {
            rep_a[i] = a;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rep_a[j][i][j] = b[i];
            }
        }

        long long det_a = det(a);
        long long det_rep[n];

        for (int i = 0; i < n; i++) {
            det_rep[i] = det(rep_a[i]);
        }

        for (int i = 0; i < n; i++) {
            cout << det_rep[i] << ' ';
        }
        
        cout << det_a << '\n';


        if (det_a == 0) {
            cout << "No unique solution";
        } else {
            cout << "Unique solution: ";

            for (int i = 0; i < n; i++) {
                long double res = (long double)det_rep[i] / det_a;

                if (-0.0005 < res && res < 0.0005) {
                    res = 0;
                }

                cout << res << ' ';
            }
        }

        cout << "\n\n";
    }
}