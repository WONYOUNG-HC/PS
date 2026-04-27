#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
int status[10][2] = {
    {0, 0},  // 0
    {7, 2},  // 1
    {3, 0},  // 2
    {4, 0},  // 3
    {4, 5},  // 4
    {7, 6},  // 5
    {9, 6},  // 6
    {0, 8},  // 7
    {7, 2},  // 8
    {4, 1},  // 9
};
int end_status[4] = {1, 5, 6, 8};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    while (tc--) {
        cin >> str;

        int cur = 1;

        for (char c : str) {
            cur = status[cur][c - '0'];
        }

        cout << (find(end_status, end_status + 4, cur) - end_status < 4 ? "YES" : "NO") << '\n';
    }
}