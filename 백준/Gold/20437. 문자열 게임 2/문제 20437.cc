#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string w;
int k;
int vis[26];
vector<int> v[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        cin >> w >> k;

        fill_n(vis, 26, 0);
        fill_n(v, 26, vector<int>());

        int answer1 = 1e9;
        int answer2 = -1;
        int left = 0;
        int right = 0;

        while (right < w.size()) {
            int index = w[right] - 'a';
            vis[index] += 1;

            if (vis[index] >= k) {
                if (vis[index] > k) {
                    vis[w[left] - 'a'] -= 1;
                    left += 1;
                }

                while (w[right] != w[left]) {
                    vis[w[left] - 'a'] -= 1;
                    left += 1;
                }

                answer1 = min(answer1, right - left + 1);
            }

            right += 1;
        }

        //
        //
        //

        for (int i = 0; i < w.size(); i++) {
            v[w[i] - 'a'].push_back(i);
        }

        for (int i = 0; i < 26; i++) {
            if (v[i].size() < k) {
                continue;
            }

            for (int j = 0; j + k - 1 < v[i].size(); j++) {
                answer2 = max(answer2, v[i][j + k - 1] - v[i][j] + 1);
            }
        }


        if (answer2 == -1) {
            cout << -1 << '\n';
        } else {
            cout << answer1 << ' ' << answer2 << '\n';
        }
    }
}