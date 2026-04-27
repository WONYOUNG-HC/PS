#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define INF (1e9 + 1)

using namespace std;

int n, maximum;

class Game {
private:
    int max_value;
    vector<vector<int>> board;
    vector<vector<bool>> merge;

public:
    explicit Game() {
        max_value = 0;
        board.resize(n + 2, vector<int>(n + 2));
        merge.resize(n + 2, vector<bool>(n + 2));
    }

    Game(const Game& ref) {
        max_value = ref.max_value;
        board = ref.board;
        merge.resize(n + 2, vector<bool>(n + 2));
    }

    void setBoard() {
        fill_n(board[0].begin(), n + 2, INF);

        for (int i = 1; i <= n; i++) {
            board[i][0] = INF;

            for (int j = 1; j <= n; j++) {
                cin >> board[i][j];
                max_value = max(max_value, board[i][j]);
            }

            board[i][n + 1] = INF;
        }

        fill_n(board[n + 1].begin(), n + 2, INF);
    }

    void up() {
        for (int j = 1; j <= n; j++) {
            for (int i = 2; i <= n; i++) {
                int value = board[i][j];
                int k = i - 1;

                board[i][j] = 0;

                while (board[k][j] == 0) k--;

                if (!merge[k][j] && board[k][j] == value) {
                    board[k][j] = value * 2;
                    merge[k][j] = true;

                    max_value = max(max_value, value * 2);
                }
                else {
                    board[k + 1][j] = value;
                }
            }
        }
    }

    void down() {
        for (int j = 1; j <= n; j++) {
            for (int i = n - 1; i >= 1; i--) {
                int value = board[i][j];
                int k = i + 1;

                board[i][j] = 0;

                while (board[k][j] == 0) k++;

                if (!merge[k][j] && board[k][j] == value) {
                    board[k][j] = value * 2;
                    merge[k][j] = true;

                    max_value = max(max_value, value * 2);
                }
                else {
                    board[k - 1][j] = value;
                }
            }
        }
    }

    void left() {
        for (int i = 1; i <= n; i++) {
            for (int j = 2; j <= n; j++) {
                int value = board[i][j];
                int k = j - 1;

                board[i][j] = 0;

                while (board[i][k] == 0) k--;

                if (!merge[i][k] && board[i][k] == value) {
                    board[i][k] = value * 2;
                    merge[i][k] = true;

                    max_value = max(max_value, value * 2);
                }
                else {
                    board[i][k + 1] = value;
                }
            }
        }
    }

    void right() {
        for (int i = 1; i <= n; i++) {
            for (int j = n - 1; j >= 1; j--) {
                int value = board[i][j];
                int k = j + 1;

                board[i][j] = 0;

                while (board[i][k] == 0) k++;

                if (!merge[i][k] && board[i][k] == value) {
                    board[i][k] = value * 2;
                    merge[i][k] = true;

                    max_value = max(max_value, value * 2);
                }
                else {
                    board[i][k - 1] = value;
                }
            }
        }
    }

    int getMax() const {
        return max_value;
    }
};

void Backtracking(Game& game, int cnt) {
    if (cnt == 5)
        return;

    if (maximum >= pow(game.getMax(), 5 - cnt + 1))
        return;

    vector<Game> arg(4, game);
    arg[0].up(); arg[1].down(); arg[2].left(); arg[3].right();

    for (int i = 0; i < 4; i++)
        maximum = max(maximum, arg[i].getMax());

    for (int i = 0; i < 4; i++)
        Backtracking(arg[i], cnt + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    Game game;
    game.setBoard();

    Backtracking(game, 0);

    cout << maximum;
}