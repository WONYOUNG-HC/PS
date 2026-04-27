#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> flower(n);
    int input;
    for (int i=0; i<n; i++) {
        for (int j=0; j<4; j++) {
            cin >> input;
            flower[i].push_back(input);
        }
    }

    sort(flower.begin(), flower.end());

    vector<int> end(2), tmp(2);
    end[0] = 3; end[1] = 1;
    int i = 0, ans = 0;
    while (end[0] <= 11) {
        if (i >= n) {
            cout << 0;
            return 0;
        }

        while (i < n && (flower[i][0] < end[0] || (flower[i][0] == end[0] && flower[i][1] <= end[1]))) {
            if (flower[i][2] > tmp[0] || (flower[i][2] == tmp[0] && flower[i][3] > tmp[1])) {
                tmp[0] = flower[i][2];
                tmp[1] = flower[i][3];
            }
            i++;
        }

        if (end == tmp) {
            cout << 0;
            return 0;
        }

        end[0] = tmp[0];
        end[1] = tmp[1];
        ans++;
    }

    cout << ans;
}