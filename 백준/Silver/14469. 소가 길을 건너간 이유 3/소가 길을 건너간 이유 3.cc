#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<pair<int, int>> cows(n);
    for (int i = 0; i < n; i++)
        cin >> cows[i].first >> cows[i].second;

    sort(cows.begin(), cows.end());

    int time = 0;
    int i = 0;
    while (i != n) {
        if (cows[i].first <= time) {
            time += cows[i].second;
            i++;
        }
        else {
            time++;
        }
    }

    cout << time;
}