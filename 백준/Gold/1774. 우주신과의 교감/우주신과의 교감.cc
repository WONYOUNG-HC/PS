#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define pdd pair<double, double>
#define X first
#define Y second

using namespace std;

struct Edge {
  int a, b;
  double dist;

  Edge(int a, int b) : a(a), b(b){};
};

int n, m;
pdd arr[1010];
bool vis[1010][1010];
vector<Edge> v;
int parent[1010], level[1010];

bool cmp(const Edge& left, const Edge& right) { return left.dist < right.dist; }

int find(int x) {
  if (x == parent[x]) {
    return x;
  }

  return parent[x] = find(parent[x]);
}

bool merge(int p, int q) {
  p = find(p);
  q = find(q);

  if (p == q) {
    return false;
  }

  if (level[p] < level[q]) {
    swap(p, q);
  }

  parent[q] = p;
  if (level[p] == level[q]) {
    level[p]++;
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i].X >> arr[i].Y;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    if (u > v) {
      swap(u, v);
    }
    vis[u][v] = true;
  }

  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      Edge e(i, j);
      e.dist = (vis[i][j] ? 0
                          : sqrt(pow(arr[i].X - arr[j].X, 2) +
                                 pow(arr[i].Y - arr[j].Y, 2)));
      v.push_back(e);
    }
  }

  sort(v.begin(), v.end(), cmp);
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
    level[i] = 1;
  }

  int cnt = 0;
  double ans = 0;
  for (Edge& e : v) {
    merge(e.a, e.b) && (cnt += 1, ans += e.dist);

    if (cnt == n - 1) {
      break;
    }
  }

  cout << fixed;
  cout.precision(2);
  cout << ans;
}