#include <iostream>
#include <string>
#include <set>
#include <cstring>

using namespace std;

int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int w, b;
string arr[300010];
set<string> word_chk;
char board[4][4];
bool vis_board[4][4];

struct Trie {
    Trie *children[26];
    bool end;

    Trie() {
        fill(children, children + 26, nullptr);
        end = false;
    }

    void insert(string str, int index = 0) {
        if (str.length() == index) {
            end = true;
            return;
        }

        int child_code = str[index] - 'A';

        if (!children[child_code]) {
            children[child_code] = new Trie();
        }

        children[child_code]->insert(str, index + 1);
    }

    bool find(string str, int index = 0) {
        if (str.length() == index) {
            return end;
        }

        int child_code = str[index] - 'A';

        if (children[child_code]) {
            return children[child_code]->find(str, index + 1);
        }

        return false;
    }

    bool prefix(string str, int index = 0) {
        if (str.size() == index) {
            return true;
        }

        int child_code = str[index] - 'A';

        if (children[child_code]) {
            return children[child_code]->prefix(str, index + 1);
        }

        return false;
    }
};

Trie *trie;

void f(string str, int y, int x) {
    if (str.size() > 8) {
        str.pop_back();
        return;
    }

    str += board[y][x];
    vis_board[y][x] = true;

    if (!trie->prefix(str)) {
        str.pop_back();
        return;
    }

    if (trie->find(str)) {
        word_chk.insert(str);
    }

    for (int *d : dir) {
        int dy = y + d[0];
        int dx = x + d[1];

        if (dy < 0 || dy > 3 || dx < 0 || dx > 3 || vis_board[dy][dx]) {
            continue;
        }

        f(str, dy, dx);
        vis_board[dy][dx] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> w;

    trie = new Trie();
    for (int i = 0; i < w; i++) {
        cin >> arr[i];
        
        trie->insert(arr[i]);
    }

    cin >> b;
    while (b--) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> board[i][j];
            }
        }

        memset(vis_board, 0, sizeof(bool) * 16);
        word_chk.clear();

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                string str = "";
                
                f(str, i, j);
                vis_board[i][j] = false;
            }
        }

        string longest_word = "";
        int score = 0;

        for (string s : word_chk) {
            switch (s.size()) {
                case 3:
                case 4:
                    score += 1;
                    break;
                case 5:
                    score += 2;
                    break;
                case 6:
                    score += 3;
                    break;
                case 7:
                    score += 5;
                    break;
                case 8:
                    score += 11;
                    break;
            }

            if (longest_word.size() < s.size() || (longest_word.size() == s.size() && s.compare(longest_word) < 0)) {
                longest_word = s;
            }
        }

        cout << score << ' ' << longest_word << ' ' << word_chk.size() << '\n';
    }
}