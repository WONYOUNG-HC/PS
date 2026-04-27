#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n;
int cnt[50], arr[50];

int dist(int a, int b) {
  int c = a ^ b;

  int ret = 0;
  for (int i = 0; i < 4; i++) {
    int bit = 1 << i;

    (c & bit) && ret++;
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n;

    fill_n(cnt, 32, 0);
    for (int i = 0; i < n; i++) {
      string str;
      cin >> str;

      int num = 0;
      for (int j = 0; j < 4; j++) {
        int bit = 0;
        if (str[j] == 'I' || str[j] == 'N' || str[j] == 'F' || str[j] == 'J') {
          bit = 1;
        }

        num |= (bit << j);
      }
      cnt[num]++;
    }

    int l = 0;
    for (int i = 0; i < 32; i++) {
      for (int j = 0; j < min(3, cnt[i]); j++) {
        arr[l++] = i;
      }
    }

    int ans = 100;
    for (int i = 0; i < l - 2; i++) {
      for (int j = i + 1; j < l - 1; j++) {
        for (int k = j + 1; k < l; k++) {
          ans = min(ans, dist(arr[i], arr[j]) + dist(arr[j], arr[k]) +
                             dist(arr[i], arr[k]));
        }
      }
    }

    cout << ans << '\n';
  }
}