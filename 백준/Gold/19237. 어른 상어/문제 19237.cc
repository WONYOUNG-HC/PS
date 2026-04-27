#include <iostream>

using namespace std;
using pii = pair<int, int>;

const int direction[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Shark {
public:
    int num;
    int dir;
    int priority[5][5];

    Shark(int x) {
        num = x;
    }

    pii next_pos(int y, int x, int cnt) {
        int move_dir = priority[dir][cnt];

        return {y + direction[move_dir][0], x + direction[move_dir][1]};
    }

    void set_dir(int cnt) {
        dir = priority[dir][cnt];
    }
};

class Pos {
public:
    int smell;
    int time;
    Shark *shark;

    Pos() {
        smell = 0;
        time = 0;
        shark = nullptr;
    }
};

int n, m, k;
Pos arr[22][22];
pii shark_pos[410];

void make_smell() {
    for (int i = 1; i <= m; i++) {
        int y = shark_pos[i].first;
        int x = shark_pos[i].second;

        arr[y][x].smell = i;
        arr[y][x].time = k;
    }
}

bool only_alive() {
    for (int i = 2; i <= m; i++) {
        if (shark_pos[i] != make_pair(0, 0)) {
            return false;
        }
    }

    return true;
}

void move_shark() {
    Pos new_arr[22][22];

    for (int i = 1; i <= m; i++) {
        int y = shark_pos[i].first;
        int x = shark_pos[i].second;

        Shark *shark = arr[y][x].shark;

        if (!shark) {
            continue;
        }

        bool move = false;
        bool die = false;

        for (int j = 0; j < 4; j++) {
            int dy = shark->next_pos(y, x, j).first;
            int dx = shark->next_pos(y, x, j).second;
            
            if (dy < 1 || dy > n || dx < 1 || dx > n) {
                continue;
            }

            if (arr[dy][dx].smell == 0) {
                new_arr[y][x].shark = nullptr;
                shark->set_dir(j);

                if (new_arr[dy][dx].shark) {
                    shark_pos[i] = {0, 0};
                    delete shark;

                    die = true;
                } else {
                    shark_pos[i] = {dy, dx};
                    new_arr[dy][dx].shark = shark;

                    move = true;
                }

                break;
            }
        }

        if (!move && !die) {
            for (int j = 0; j < 4; j++) {
                int dy = shark->next_pos(y, x, j).first;
                int dx = shark->next_pos(y, x, j).second;

                if (dy < 1 || dy > n || dx < 1 || dx > n) {
                   continue;
                }

                if (arr[dy][dx].smell == i) {
                    new_arr[y][x].shark = nullptr;
                    shark->set_dir(j);

                    if (new_arr[dy][dx].shark) {
                        shark_pos[i] = {0, 0};
                        delete shark;

                        die = true;
                    } else {
                        shark_pos[i] = {dy, dx};
                        new_arr[dy][dx].shark = shark;
                        
                        move = true;
                    }

                    break;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j].shark = new_arr[i][j].shark;
        }
    }
}

void reduce_smell() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j].smell != 0) {
                arr[i][j].time -= 1;

                if (arr[i][j].time == 0) {
                    arr[i][j].smell = 0;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;

            cin >> x;

            if (x == 0) {
                arr[i][j].shark = nullptr;
            } else {
                Shark *shark = new Shark(x);
                
                arr[i][j].shark = shark;
                shark_pos[x] = {i, j};
            }

            arr[i][j].smell = 0;
            arr[i][j].time = 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        int y = shark_pos[i].first;
        int x = shark_pos[i].second;

        cin >> arr[y][x].shark->dir;
    }

    for (int i = 1; i <= m; i++) {
        int y = shark_pos[i].first;
        int x = shark_pos[i].second;
        Shark *shark = arr[y][x].shark;

        for (int j = 1; j <= 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> shark->priority[j][k];
            }
        }
    }

    for (int t = 0; t <= 1000; t++) {
        if (only_alive()) {
            cout << t;

            return 0;
        }

        make_smell();

        move_shark();

        reduce_smell();
    }

    cout << -1;
}