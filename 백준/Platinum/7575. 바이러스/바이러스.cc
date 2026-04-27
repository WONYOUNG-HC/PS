#include <iostream>

using namespace std;

int n, k;
int code[110][1010];
int code_len[110];

void make_pi(int *pat, int *pi) {
    int j = 0;

    for (int i = 1; i < k; i++) {
        while (j > 0 && pat[i] != pat[j]) {
            j = pi[j - 1];
        }

        if (pat[i] == pat[j]) {
            j += 1;
            pi[i] = j;
        }
    }
}

bool match_code(int *c, int l, int *pat, int *pi) {
    if (l < k) {
        return false;
    }

    int j = 0;

    for (int i = 0; i < l; i++) {
        while (j > 0 && c[i] != pat[j]) {
            j = pi[j - 1];
        }

        if (c[i] == pat[j]) {
            if (j == k - 1) {
                return true; 
            }

            j += 1;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> code_len[i];

        for (int j = 0; j < code_len[i]; j++) {
            cin >> code[i][j];
        }
    }

    for (int i = 0; i < code_len[0] - k + 1; i++) {
        int pat1[1010];
        int pat2[1010];
        int pi1[1010] {};
        int pi2[1010] {};

        for (int j = 0; j < k; j++) {
            pat1[j] = code[0][i + j];
            pat2[k - j - 1] = pat1[j];
        }

        make_pi(pat1, pi1);
        make_pi(pat2, pi2);

        bool flag = true;

        for (int j = 1; j < n; j++) {
            flag &= match_code(code[j], code_len[j], pat1, pi1) || match_code(code[j], code_len[j], pat2, pi2);

            if (!flag) {
                break;
            }
        }

        if (flag) {
            cout << "YES";

            return 0;
        }
    }

    cout << "NO";
}