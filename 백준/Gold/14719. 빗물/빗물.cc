#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    vector<int> block(w);
    for (int i = 0; i < w; i++)
        cin >> block[i];

    vector<int> ceil(w);
    int upper = *max_element(block.begin(), block.end());
    while (upper > 0) {
        int start = -1, end = -1;

        for (int i = 0; i < w; i++) {
            if (block[i] >= upper) {
                if (start == -1) start = i;
                else end = i;
            }
        }

        for (int i = start; i <= end; i++) {
            ceil[i] = max(ceil[i], upper);
        }

        upper--;
    }

    int ans = 0;
    for (int i = 0; i < w; i++) {
        if (ceil[i] - block[i] > 0)
            ans += ceil[i] - block[i];
    }

    cout << ans;
}