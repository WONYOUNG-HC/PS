#include <iostream>
#include <vector>

using namespace std;

int dir_fish[9][2] = {{0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
int dir_shark[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

class Fish {
public:
    int y, x, d;

    Fish(int _y, int _x, int _d) {
        y = _y;
        x = _x;
        d = _d;
    }
};

class Shark {
public:
    int y, x;

    Shark(int _y = 0, int _x = 0) {
        y = _y;
        x = _x;
    }
};

class Pos {
public:
    vector<Fish> fishes;
    bool shark = false;
    int smell = 0;
};

int m, s;
Pos arr[6][6];
Shark shark;
vector<Fish> fish_copy;
vector<string> shark_routes;

void copy_fish() {
    fish_copy.clear();

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            for (Fish fish : arr[i][j].fishes) {
                fish_copy.push_back(fish);
            }
        }
    }
}

void paste_fish() {
    for (Fish fish : fish_copy) {
        arr[fish.y][fish.x].fishes.push_back(Fish(fish));
    }
}

void make_shark() {
    arr[shark.y][shark.x].shark = true;
}

bool can_fish_move(int dy, int dx) {
    if (dy < 1 || dy > 4 || dx < 1 || dx > 4) {
        return false;
    }

    if (arr[dy][dx].shark) {
        return false;
    }

    if (arr[dy][dx].smell > 0) {
        return false;
    }

    return true;
}

void move_fish() {
    Pos next[6][6];

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            for (Fish fish : arr[i][j].fishes){
                bool is_fish_move = false;

                for (int k = 0; k < 8; k++) {
                    int dir = (((fish.d - 1) - k + 8) % 8) + 1;

                    int dy = i + dir_fish[dir][0];
                    int dx = j + dir_fish[dir][1];

                    if (can_fish_move(dy, dx)) {
                        is_fish_move = true;
                        next[dy][dx].fishes.push_back(Fish(dy, dx, dir));

                        break;
                    }
                }

                if (!is_fish_move) {
                    next[i][j].fishes.push_back(Fish(fish));
                }
            }
        }
    }

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            swap(arr[i][j].fishes, next[i][j].fishes);
        }
    }
}

void make_shark_routes() {
    string route = "";

    for (int i = 0; i < 4; i++) {
        route = to_string(i);

        for (int j = 0; j < 4; j++) {
            route += to_string(j);

            for (int k = 0; k < 4; k++) {
                route += to_string(k);

                shark_routes.push_back(route);

                route.pop_back();
            }

            route.pop_back();
        }
    }
}

void reduce_smell() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (arr[i][j].smell > 0) {
                arr[i][j].smell -= 1;
            }
        }
    }
}

void move_shark() {
    pair<int, string> max_move = {-1e9, ""};

    for (string route : shark_routes) {
        bool vis[6][6] = {};
        int y = shark.y;
        int x = shark.x;
        int fish = 0;

        for (char dir_char : route) {
            int dir = dir_char - '0';

            y += dir_shark[dir][0];
            x += dir_shark[dir][1];

            if (y < 1 || y > 4 || x < 1 || x > 4) {
                fish = -1e9;

                break;
            }

            if (!vis[y][x] && arr[y][x].fishes.size() > 0) {
                vis[y][x] = true;
                fish += arr[y][x].fishes.size();
            }
        }

        if (max_move.first < fish || (max_move.first == fish && route < max_move.second)) {
            max_move = {fish, route};
        }
    }

    arr[shark.y][shark.x].shark = false;

    for (char dir_char : max_move.second) {
        int dir = dir_char - '0';

        shark.y += dir_shark[dir][0];
        shark.x += dir_shark[dir][1];

        if (arr[shark.y][shark.x].fishes.size() > 0) {
            arr[shark.y][shark.x].smell = 3;
            arr[shark.y][shark.x].fishes.clear();
        }
    }

    arr[shark.y][shark.x].shark = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> s;

    for (int i = 0; i < m; i++) {
        int y, x, d;

        cin >> y >> x >> d;

        fish_copy.push_back(Fish(y, x, d));
    }

    int sy, sx;

    cin >> sy >> sx;

    shark = Shark(sy, sx);

    paste_fish();
    make_shark();
    make_shark_routes();

    for (int i = 0; i < s; i++) {
        copy_fish();
        move_fish();
        move_shark();
        reduce_smell();
        paste_fish();
    }

    int ans = 0;

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            ans += arr[i][j].fishes.size();
        }
    }
    
    cout << ans;
}