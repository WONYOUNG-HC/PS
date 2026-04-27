#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<bool> prime_nums(10000, true);

void eratosthenes();
int bfs(int start, int target);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    eratosthenes();

    int tc; cin >> tc;
    while (tc--) {
        int start, target;
        cin >> start >> target;

        int ans = bfs(start, target);

        if (ans == -1)
            cout << "Impossible \n";
        else
            cout << ans << '\n';
    }
}

void eratosthenes() {
    for (int i = 2; i <= sqrt(9999); i++) {
        if (!prime_nums[i])
            continue;

        int j = i + i;
        while (j <= 9999) {
            prime_nums[j] = false;
            j += i;
        }
    }
}

int bfs(int start, int target) {
    vector<int> dist(10000, -1);
    dist[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == target)
            return dist[cur];

        for (int i = 0; i < 4; i++) {
            string num = to_string(cur);

            for (char j = '0'; j <= '9'; j++) {
                if (i == 0 && j == '0')
                    continue;

                num[i] = j;
                int next = stoi(num);
                if (prime_nums[next] && dist[next] == -1) {
                    dist[next] = dist[cur] + 1;
                    q.push(next);
                }
            }
        }
    }

    return -1;
}