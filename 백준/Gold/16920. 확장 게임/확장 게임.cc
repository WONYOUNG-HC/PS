#include <algorithm>
#include <iostream>
#include <queue>

#define pii pair<int, int>
#define Y first
#define X second

using namespace std;

int n, m, p;
char arr[1010][1010];
int s[10];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<pii> q[10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> p;
  for (int i = 1; i <= p; i++) {
    cin >> s[i];
  }

  fill_n(&arr[0][0], 1010 * 1010, '#');
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];

      if ('1' <= arr[i][j] && arr[i][j] <= '9') {
        q[arr[i][j] - '0'].emplace(i, j);
      }
    }
  }

  bool flag = true;
  while (flag) {
    for (int i = 1; i <= p; i++) {
      for (int j = 0; j < s[i]; j++) {
        if (q[i].empty()) {
          break;
        }

        queue<pii> _q;
        while (!q[i].empty()) {
          int y = q[i].front().Y;
          int x = q[i].front().X;
          q[i].pop();

          for (int* d : dir) {
            int dy = y + d[0];
            int dx = x + d[1];

            if (arr[dy][dx] == '.') {
              arr[dy][dx] = i + '0';
              _q.emplace(dy, dx);
            }
          }
        }

        q[i].swap(_q);
      }
    }

    flag = false;
    for (int i = 1; i <= p; i++) {
      if (!q[i].empty()) {
        flag = true;
        break;
      }
    }
  }

  fill_n(s, 10, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if ('1' <= arr[i][j] && arr[i][j] <= '9') {
        s[arr[i][j] - '0']++;
      }
    }
  }

  for (int i = 1; i <= p; i++) {
    cout << s[i] << ' ';
  }
}