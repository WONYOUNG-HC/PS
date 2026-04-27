#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LineLen(int n, vector<pair<int, int>>& line);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<pair<int, int>> line(n);
    for (int i=0; i<n; i++)
        cin >> line[i].first >> line[i].second;

    cout << LineLen(n, line);
}

int LineLen(int n, vector<pair<int, int>>& line) {
    sort(line.begin(), line.end());

    int ans = line[0].second - line[0].first;
    int end = line[0].second;
    for (int i=1; i<n; i++) {
        if (end >= line[i].second)
            continue;

        ans += line[i].second - max(line[i].first, end);
        end = line[i].second;
    }

    return ans;
}