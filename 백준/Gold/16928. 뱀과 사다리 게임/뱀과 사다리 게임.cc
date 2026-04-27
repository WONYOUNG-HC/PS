#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Game {
private:
    vector<int> board;
    vector<int> pass;
    vector<bool> visited;
    int num;

public:
    explicit Game(int n, int m) : num(1) {
        board.resize(101);
        pass.resize(n+m+1);
        visited.resize(101);
    }

    void SetPass(int x, int y) {
        board[x] = num;
        pass[num] = y;
        num++;
    }

    int Bfs() {
        int pos = 1, cnt = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(pos, cnt));
        visited[pos] = true;

        while (true) {
            pos = q.front().first;
            cnt = q.front().second;
            q.pop();

            if (pos+6 >= 100)
                return cnt + 1;

            int arrive;
            for (int i=1; i<=6; i++) {
                if (visited[pos+i])
                    continue;

                if (board[pos+i]) {
                    arrive = pass[board[pos+i]];
                    q.push(make_pair(arrive, cnt+1));
                    visited[arrive] = true;
                }
                else {
                    q.push(make_pair(pos+i, cnt+1));
                    visited[pos+i] = true;
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Game game(n, m);
    int x, y;
    for (int i=0; i<n+m; i++) {
        cin >> x >> y;
        game.SetPass(x, y);
    }

    cout << game.Bfs();
}