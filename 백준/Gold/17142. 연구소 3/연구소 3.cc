#include <iostream>
#include <queue>
#include <vector>

#define pii pair<int, int>
#define Y first
#define X second

using namespace std;

int n, m, v;
int arr[55][55], narr[55][55];
bool vis[55][55];
int dir[4][2]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
pii vir[11];
vector<vector<pii>> pv;

void permu(int x, vector<pii>& vv) {
  if (vv.size() == m) {
    pv.push_back(vv);
    return;
  }

  for (int i = x; i < v; i++) {
    vv.push_back(vir[i]);
    permu(i + 1, vv);
    vv.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  fill_n(&arr[0][0], 55 * 55, 1);
  int zer = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> arr[i][j];

      if (arr[i][j] == 2) {
        vir[v++] = {i, j};
      }

      arr[i][j] == 0 && zer++;
    }
  }

  if (zer == 0) {
    cout << 0;
    return 0;
  }

  vector<pii> vv;
  permu(0, vv);

  int ans = 10000;
  for (auto& vp : pv) {
    for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j <= n + 1; j++) {
        narr[i][j] = arr[i][j];
      }
    }

    queue<pii> q, _q;
    for (pii& pr : vp) {
      q.push(pr);
      vis[pr.Y][pr.X] = true;
    }

    int cnt = 0, nzer = zer;
    fill_n(&vis[0][0], 55 * 55, false);
    while (!q.empty()) {
      while (!q.empty()) {
        int y = q.front().Y;
        int x = q.front().X;
        q.pop();

        for (int* d : dir) {
          int dy = y + d[0];
          int dx = x + d[1];

          if (narr[dy][dx] == 1 || vis[dy][dx]) {
            continue;
          }

          narr[dy][dx] == 0 && nzer--;
          vis[dy][dx] = true;
          narr[dy][dx] = 2;
          _q.emplace(dy, dx);
        }
      }

      q.swap(_q);
      cnt++;

      if (nzer == 0) {
        break;
      }
    }

    nzer > 0 && (cnt = 10000);
    ans = min(ans, cnt);
  }

  cout << (ans == 10000 ? -1 : ans);
}