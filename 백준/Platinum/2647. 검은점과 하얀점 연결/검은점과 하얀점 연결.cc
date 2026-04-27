#include <iostream>
#include <vector>
#include <algorithm>

#define DIST first
#define HIGH second

using namespace std;

string point;
vector<vector<int>> dp;
vector<vector<int>> height;
vector<vector<int>> touch;

void Init(int n);
pair<int, int> MinDist(int start, int end);
void Trace(int start, int end);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> point;

    Init(n);
    int ans = MinDist(0, n-1).DIST;
    cout << ans << '\n';
    Trace(0, n-1);
}

void Init(int n) {
    dp.resize(n, vector<int>(n, -1));
    height.resize(n, vector<int>(n));
    touch.resize(n, vector<int>(n));
}

pair<int, int> MinDist(int start, int end) {
    if (start > end)
        return {0, 0};
    if (dp[start][end] != -1)
        return {dp[start][end], height[start][end]};

    dp[start][end] = 0;
    int min_dist = 1e9, high;
    for (int div = start + 1; div <= end; div += 2) {
        if (point[start] == point[div])
            continue;

        pair<int, int> left = MinDist(start+1, div-1);
        pair<int, int> right = MinDist(div+1, end);
        int cur_dist = div - start;

        if (min_dist > left.DIST + right.DIST + cur_dist + (left.HIGH + 1) * 2) {
            min_dist = left.DIST + right.DIST + cur_dist + (left.HIGH + 1) * 2;
            high = max(left.HIGH + 1, right.HIGH);
            touch[start][end] = div;
        }
    }

    dp[start][end] = min_dist;
    height[start][end] = high;
    return {dp[start][end], height[start][end]};
}

void Trace(int start, int end) {
    if (start > end)
        return;

    int div = touch[start][end];
    cout << start + 1 << ' ' << div + 1 << '\n';

    Trace(start+1, div-1);
    Trace(div+1, end);
}