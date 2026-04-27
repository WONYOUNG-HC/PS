#include <iostream>
#include <queue>

using namespace std;

int dy[] = {-1,0, 0, 1};
int dx[] = {0,-1, 1, 0};

int graph[20][20];
int n;

class Shark {
private:
    pair<int, int> pos;
    pair<int, int> fish;
    int size;
    int cnt;
    int time;
    int dist;

public:
    explicit Shark(pair<int, int> pos) : pos(std::move(pos)), size(2), cnt(0), time(0), dist(4000) {}

    bool Bfs() {
        queue<pair<int, int>> q;
        q.push(pair<int, int>(pos.first, pos.second));
        vector<vector<int>> dp(n);
        for (int  i=0; i<n; i++)
            dp[i].resize(n, 4000);
        dp[pos.first][pos.second] = 0;
        dist = 4000;

        bool flag = false;
        pair<int, int> point;
        while (!q.empty()) {
            point = q.front();
            q.pop();

            int ny, nx;
            for (int i=0; i<4; i++) {
                ny = point.first + dy[i];
                nx = point.second + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                    continue;

                if (graph[ny][nx] > size)
                    continue;

                if (dp[ny][nx] > dp[point.first][point.second] + 1) {
                    dp[ny][nx] = dp[point.first][point.second] + 1;
                    q.push(pair<int, int>(ny, nx));
                }

                if (graph[ny][nx] > 0 && graph[ny][nx] < size) {
                    if (dist < dp[ny][nx])
                        continue;
                    if (dist == dp[ny][nx] && (fish.first < ny || (fish.first == ny && fish.second < nx)))
                        continue;

                    dist = dp[ny][nx];
                    fish = pair<int, int>(ny, nx);
                    flag = true;
                }
            }
        }

        return flag;
    }

    void EatFish() {
        if (size == cnt + 1) {
            cnt = 0;
            size++;
        }
        else {
            cnt++;
        }
        graph[fish.first][fish.second] = 0;
        pos = fish;
        time += dist;
    }

    void ShowTime() {
        cout << time;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int input;
    pair<int, int> pos;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> input;
            if (input == 9) pos = {i, j};
            else if(input > 0)  graph[i][j] = input;
        }
    }

    Shark shark(pos);

    while (shark.Bfs())
        shark.EatFish();

    shark.ShowTime();
}
