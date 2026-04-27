#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, p;
    cin >> n >> s >> p;

    vector<int> board(p+1, -1);
    for (int i=1; i<=n; i++)
        cin >> board[i];

    int rank = 1;
    for (int i=1; i<=p; i++) {
        if (board[i] != board[i-1] && board[i-1] != s)
            rank = i;

        if (s > board[i]) {
            cout << rank;
            return 0;
        }
    }

    cout << -1;
}