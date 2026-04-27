#include <iostream>
#include <string>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string graph[100];
bool visited_normal[100][100];
bool visited_blind[100][100];
int n;

void BfsNormal(int y, int x);
void BfsBlind(int y, int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    string input;
    for (int i=0; i<n; i++) {
        cin >> input;
        graph[i] = input;
    }

    int cnt_normal = 0, cnt_blind = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!visited_normal[i][j]) {
                BfsNormal(i, j);
                cnt_normal++;
            }

            if (!visited_blind[i][j]) {
                BfsBlind(i, j);
                cnt_blind++;
            }
        }
    }

    cout << cnt_normal << ' ' << cnt_blind;
}

void BfsNormal(int y, int x) {
    char color = graph[y][x];
    queue<pair<int, int>> q;
    q.push(pair<int, int>(y, x));
    visited_normal[y][x] = true;

    pair<int, int> pr;
    while (!q.empty()) {
        pr = q.front();
        q.pop();

        int ny, nx;
        for (int i=0; i<4; i++) {
            ny = pr.first + dy[i];
            nx = pr.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;

            if (graph[ny][nx] == color && !visited_normal[ny][nx]) {
                visited_normal[ny][nx] = true;
                q.push(pair<int, int>(ny, nx));
            }
        }
    }
}

void BfsBlind(int y, int x) {
    char color = graph[y][x];
    queue<pair<int, int>> q;
    q.push(pair<int, int>(y, x));
    visited_normal[y][x] = true;

    pair<int, int> pr;
    while (!q.empty()) {
        pr = q.front();
        q.pop();

        int ny, nx;
        for (int i=0; i<4; i++) {
            ny = pr.first + dy[i];
            nx = pr.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;

            if (color == 'B') {
                if (graph[ny][nx] == 'B' && !visited_blind[ny][nx]) {
                    visited_blind[ny][nx] = true;
                    q.push(pair<int, int>(ny, nx));
                }
            }
            else {
                if (graph[ny][nx] != 'B' && !visited_blind[ny][nx]) {
                    visited_blind[ny][nx] = true;
                    q.push(pair<int, int>(ny, nx));
                }
            }
        }
    }
}