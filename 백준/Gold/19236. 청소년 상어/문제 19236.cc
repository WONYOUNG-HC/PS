#include <iostream>
#include <vector>

using namespace std;

const int n = 4;
const int direction[8][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

class Fish {
public:
    int num;
    int dir;
    int row, col;

    Fish(int id, int d, int r, int c) {
        num = id;
        dir = d;
        row = r;
        col = c;
    }

    Fish(Fish &fish) {
        num = fish.num;
        dir = fish.dir;
        row = fish.row;
        col = fish.col;
    }

    void rotate() {
        dir = (dir + 1) % 8;
    }
};

int ans = 0;

void f(vector<vector<Fish *>> graph, vector<Fish *> arr, Fish *shark, int cur) {
    vector<vector<Fish *>> new_graph(n + 2, vector<Fish *>(n + 2, nullptr));
    vector<Fish *> new_arr(n * n + 10, nullptr);
    Fish *new_shark = new Fish(*shark);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j]) {
                new_graph[i][j] = new Fish(*graph[i][j]);
                new_arr[new_graph[i][j]->num] = new_graph[i][j];
            }
        }
    }

    ans = max(ans, cur);

    for (int i = 1; i <= n * n; i++) {
        if (new_arr[i] == nullptr) {
            continue;
        }

        Fish *fish = new_arr[i];

        for (int j = 0; j < 8; j++) {
            int r = fish->row;
            int c = fish->col;

            int dr = r + direction[fish->dir][0];
            int dc = c + direction[fish->dir][1];

            if (dr < 1 || dr > n || dc < 1 || dc > n) {
                fish->rotate();
                continue;
            }

            if (new_shark->row == dr && new_shark->col == dc) {
                fish->rotate();
                continue;
            }

            Fish *df = new_graph[dr][dc];

            fish->row = dr;
            fish->col = dc;

            if (df) {
                df->row = r;
                df->col = c; 
            }

            swap(new_graph[r][c], new_graph[dr][dc]);

            break;
        }
    }

    int sr = new_shark->row;
    int sc = new_shark->col;
    int sd = new_shark->dir;

    while (true) {
        sr += direction[sd][0];
        sc += direction[sd][1];

        if (sr < 1 || sr > n || sc < 1 || sc > n) {
            break;
        }

        if (new_graph[sr][sc]) {
            Fish *eat = new_graph[sr][sc];
            new_shark->row = sr;
            new_shark->col = sc;
            new_shark->dir = eat->dir;

            new_graph[sr][sc] = nullptr;
            arr[eat->num] = nullptr;

            f(new_graph, new_arr, new_shark, cur + eat->num);

            new_graph[sr][sc] = eat;
            arr[eat->num] = eat;
        }
    }

    for (int i = 1; i <= n * n; i++) {
        if (new_arr[i]) {
            delete new_arr[i];
        }
    }

    delete new_shark;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<Fish *>> graph(n + 2, vector<Fish *>(n + 2, nullptr));
    vector<Fish *> arr(n * n + 10, nullptr);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a, b;

            cin >> a >> b;

            graph[i][j] = new Fish(a, b - 1, i, j);
            arr[a] = graph[i][j];
        }
    }

    Fish *shark = new Fish(-1, graph[1][1]->dir, 1, 1);

    int cur = graph[1][1]->num;

    arr[cur] = nullptr;
    graph[1][1] = nullptr;

    f(graph, arr, shark, cur);

    cout << ans;
}