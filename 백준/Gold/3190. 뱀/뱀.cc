#include <iostream>
#include <deque>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0,-1};

int graph[101][101];
int n;

class Snake {
private:
    deque<pair<int, int>> body;
    pair<int, int> head;
    int direction;
public:
    explicit Snake() : direction(0) {
        body.emplace_front(1, 1);
        head = pair<int, int>(1, 1);
    }

    void SetDirection(char c) {
        if (c == 'D') {
            direction += 1;
            if (direction > 3)
                direction = 0;
        }
        else if (c == 'L') {
            direction -= 1;
            if (direction < 0)
                direction = 3;
        }
    }

    void Expand() {
        head.first += dy[direction];
        head.second += dx[direction];
        body.push_front(head);
    }

    bool IsCollision () {
        int y = head.first;
        int x = head.second;

        if (y < 1 || y > n || x < 1 || x > n)
            return true;

        for (deque<pair<int, int>>::size_type i=1; i<body.size(); i++) {
            if (y == body[i].first && x == body[i].second)
                return true;
        }

        return false;
    }

    void Shrink() {
        body.pop_back();
    }

    bool Move() {
        Expand();

        if (IsCollision())
            return false;

        if (graph[head.first][head.second] == 0)
            Shrink();
        else
            graph[head.first][head.second] = 0;

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> n >> k;

    int y, x;
    for (int i=0; i<k; i++) {
        cin >> y >> x;
        graph[y][x] = 1;
    }

    Snake snake;

    int l, t, time=0;
    cin >> l;
    char c;
    for (int i=0; i<l; i++) {
        cin >> t >> c;

        for (; time<t; time++) {
            if (!snake.Move()) {
                cout << time + 1;
                return 0;
            }
        }

        snake.SetDirection(c);
    }

    while (snake.Move())
        time++;

    cout << time + 1;

}