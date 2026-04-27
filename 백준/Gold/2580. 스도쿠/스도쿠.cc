#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Sudoku {
public:
    int board[9][9];

    explicit Sudoku() {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> board[i][j];
    }

    pair<int, int> findEmpty() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == 0)
                    return {i, j};
            }
        }

        return {-1, -1};
    }

    bool check(int y, int x) {
        int num = board[y][x];

        for (int i = 0; i < 9; i++) {
            if (i != y && board[i][x] == num)
                return false;
        }

        for (int j = 0; j < 9; j++) {
            if (j != x && board[y][j] == num)
                return false;
        }

        int p, q;
        if (y < 3) p = 0;
        else if (y < 6) p = 3;
        else p = 6;

        if (x < 3) q = 0;
        else if (x < 6) q = 3;
        else q = 6;

        for (int i = p; i < p + 3; i++) {
            for (int j = q; j < q + 3; j++) {
                if (i != y && j != x && board[i][j] == num)
                    return false;
            }
        }

        return true;
    }
};

void Backtracking(Sudoku& sudoku) {
    pair<int, int> pr = sudoku.findEmpty();
    int y = pr.first, x = pr.second;

    if (y == -1) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << sudoku.board[i][j] << ' ';
            cout << '\n';
        }

        exit(0);
    }

    for (int k = 1; k <= 9; k++) {
        sudoku.board[y][x] = k;

        if (sudoku.check(y, x))
            Backtracking(sudoku);
    }

    sudoku.board[y][x] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Sudoku sudoku;

    Backtracking(sudoku);
}