#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Arr {
public:
    int n;
    int r, c;
    int arr[55][55] = {};

    Arr(int _n) {
        n = _n;
        r = c = (n + 1) / 2;
    }

    int &at(int y, int x) {
        return arr[y][x];
    }

    int &at(int idx) {
        int stand[4][2] = {{r, c - 1}, {r + 1, c}, {r, c + 1}, {r - 1, c}};
        int span[4][2] = {{-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
        int step[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        int rt_odd = sqrt(idx);

        if (rt_odd % 2 == 0) {
            rt_odd -= 1;
        }

        int phase = (rt_odd + 1) / 2;
        int k = idx - (rt_odd * rt_odd);

        int diviser = k / (phase * 2);
        int remainder = k % (phase * 2);

        int y = stand[diviser][0] + (span[diviser][0] * (phase - 1)) + (step[diviser][0] * remainder);
        int x = stand[diviser][1] + (span[diviser][1] * (phase - 1)) + (step[diviser][1] * remainder);

        return arr[y][x];
    }

    void destroy(int d, int s) {
        int dir[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int y = r;
        int x = c;

        for (int i = 0; i < s; i++) {
            y += dir[d][0];
            x += dir[d][1];

            arr[y][x] = 0;
        }
    }

    void fill() {
        int idx = 1;

        while (idx < n * n) {
            int j = idx;

            while (j < n * n && this->at(j) == 0) {
                j += 1;
            }

            if (j == n * n) {
                break;
            }

            swap(this->at(idx), this->at(j));

            idx += 1;
        }
    }

    vector<int> explode() {
        vector<int> ret(4);

        int idx = 1;

        while (idx < n * n) {
            int start = idx;

            idx += 1;

            while (idx < n * n && this->at(idx) == this->at(start)) {
                idx += 1;
            }

            if (idx - start >= 4) {
                for (int i = start; i < idx; i++) {
                    ret[this->at(i)] += 1;
                    this->at(i) = 0;
                }
            }
        }

        return ret;
    }

    void change() {
        vector<pair<int, int>> groups;

        int idx = 1;

        while (idx < n * n && this->at(idx) != 0) {
            int start = idx;

            idx += 1;

            while (idx < n * n && this->at(start) == this->at(idx)) {
                idx += 1;
            }

            groups.push_back({idx - start, this->at(start)});
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                arr[i][j] = 0;
            }
        }

        for (int i = 0; i < groups.size(); i++) {
            int idx = i * 2 + 1;

            if (idx >= n * n) {
                break;
            }

            this->at(idx) = groups[i].first;

            if (idx + 1 >= n * n) {
                break;
            }

            this->at(idx + 1) =  groups[i].second;
        }
    }
};

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    Arr arr(n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr.at(i, j);
        }
    }

    int ans = 0;

    while (m--) {
        int d, s;

        cin >> d >> s;

        arr.destroy(d, s);
        arr.fill();

        while (true) {
            vector<int> cnt = arr.explode();

            if (cnt[1] + cnt[2] + cnt[3] == 0) {
                break;
            }

            ans += cnt[1] + (cnt[2] * 2) + (cnt[3] * 3);

            arr.fill();
        }

        arr.change();
    }

    cout << ans;
}